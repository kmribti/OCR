#include "image_io.h"

namespace image_io 
{
    
    void displayImage(CImg<>& img, const char* title){
        CImgDisplay main_disp(img, title,0);
        while (!main_disp.is_closed()){
            main_disp.wait();
        }
    }
    
    CImg<> import(const char* path){
        CImg<int> importedImage;
        try{
            importedImage = CImg<>(path);
        }catch(const cimg_library::CImgIOException &){
            std::cerr << "Error during import. FilePath: " << path << std::endl;
            exit(1);
        }

        // translate into grayscale. If spectrum is equal to one,
        // already in gray.
        if(importedImage._spectrum > 1){
            importedImage = importedImage.get_RGBtoYCbCr().get_channel(0);
        }
        
        return importedImage;
    }

    bool extract_images(const char* path, std::vector< CImg<>* >& images){
        directory_iterator end_itr;
        for(directory_iterator it(path); it != end_itr; ++it) { 
            if(is_regular_file(it->status())) { //&& it->path().extension() == ".png"
                // This is an image
                CImg<>* image  = new CImg<>(import(it->path().string().c_str()));
                *image = projection::reduce(*image).resize(SQUARE, SQUARE);
                images.push_back(image);
            } else {
                // There is a directory at this level
                return false;
            }
        }
        return true;
    }
    
    bool extract_images_compressed(const char* path, std::vector< CImg<>* >& images){
        directory_iterator end_itr;
        for(directory_iterator it(path); it != end_itr; ++it) { 
            if(is_regular_file(it->status())) { 
                // This is an image
                CImg<> image(import(it->path().string().c_str()));
                
                unsigned int x = 0;
                while (x + SQUARE < image._width) {
                    CImg<>* tmp = new CImg<>(image.get_crop(x, x + SQUARE - 1));
                    images.push_back(tmp);
                    x += SQUARE;
                } 
            } else {
                // There is a directory at this level
                return false;
            }
        }
        return true;
    }
    
    void delete_images(std::vector< CImg<>* > images) {
        while (!images.empty()) {
            delete images.back();
            images.pop_back();
        }
    }
    
    void exportAll(const char* path, std::vector< CImg<>* > list){
        int index = 0;
        for(std::vector< CImg<>* >::iterator it = (list.begin()++); it != list.end(); it++){
            // create file's name
            std::stringstream ss;
            ss << path << "_" << index << ".png";
            (*it)->save(ss.str().c_str());
            index++;
        }
    }
    
    void exportAll_compressed(const char* path, std::vector< CImg<>* > list){
        std::stringstream ss;
        ss << path << ".png";
        CImg<> res(list.size()*SQUARE, SQUARE);
        int x = 0;
        for(std::vector< CImg<>* >::iterator it = list.begin(); it != list.end(); it++){
            // create file's name
            assert((*it)->_height == (*it)->_width && (*it)->_height == SQUARE);
            res.draw_image(x, **it);
            x += SQUARE;
        }
        res.save(ss.str().c_str());
    }
    
    CImg<> average(std::vector< CImg<>* > list){
        CImg<> res(*list.at(0));
        for(std::vector< CImg<>* >::iterator it = (++list.begin()); it != list.end(); it++){
            res += (**it);
        }
        return res / list.size();
    }
    
};

