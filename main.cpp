#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include "Image_Class.h"
using namespace std;

//دى اول استيب فى البرةوجيكت انى جهزت المكاتب و ظبطت المكاتب الى عاملها دكتور الرملى و عشان هى مكاتب محليه بتتعمل ب""



void Grayscale(Image& img) {
  
    
    
    
    for (int i = 0; i < img.width; ++i) {
      
        
        for (int j = 0; j < img.height; ++j) {
            
            
            
            
            int avg = (img(i, j, 0) + img(i, j, 1) + img(i, j, 2)) / 3;

            img(i, j, 0) = avg;
            img(i, j, 1) = avg;
            img(i, j, 2) = avg;
        }
    }
}
  // ده اول فلتر شغلته انه بيحول الصورة لرمادى عن طريق انه بيجيب الافريدج للتلت الوان و يساويهم بيه و هما الاحمر و الازرق و الاخضر
// اول لوب بنلف بيها على كل سطر من البيكسل و تانى لوب على كل عمود
// بعدها خدت الافريدج و ساويته بالتلت الوان
//لوب دى خطوه ثابته هعملها فى كل فلترfor ال 



void rotateImage(Image& img) {

    int method;


  
        cout << "1. flip 90 degrees\n";
        cout << "2. flip 180 degrees\n";
        cout << "3. flip 270 degrees\n";
        cout << "Choose: ";


        cin >> method;



       
        
        
        
        
        if (method == 1) {
           
            
            Image tImg(img.height, img.width);
           
            
            for (int i = 0; i < img.width; ++i) {
               
                
                for (int j = 0; j < img.height; ++j) {
                
                    
                    tImg(img.height - 1 - j, i, 0) = img(i, j, 0);
                   
                    tImg(img.height - 1 - j, i, 1) = img(i, j, 1);
                  
                    tImg(img.height - 1 - j, i, 2) = img(i, j, 2);
                }
            }
            img = tImg;
        }
        

        // الاول عملت صوره موقته بس عشان انقل فيها الصفوف و الاعمده بالترتيب الجديد الى هعملوا

        // انا هنا عايزها تتقلب 90درجه فكل الى هعملوا انى هخلى الاعمده تبقى صفوف و الصفوف اعمده و ده ان
        


        
        
        
        
        
        
        
        else if (method == 2) {
            Image tImg(img.width, img.height);
           
            
            
            
            
            for (int i = 0; i < img.width; ++i) {
               
                
                
                
                
                for (int j = 0; j < img.height; ++j) {
                    
                    
                    tImg(img.width - 1 - i, img.height - 1 - j, 0) = img(i, j, 0);
                   
                    
                    tImg(img.width - 1 - i, img.height - 1 - j, 1) = img(i, j, 1);
                   
                    
                    tImg(img.width - 1 - i, img.height - 1 - j, 2) = img(i, j, 2);
                }
            }
            img = tImg;
        }




        // الجزه ده عشان اقلب الصوره اللى فوق تحت و الى تحت فوق
        //هنا اخر بيكسل فى الصف او العمود بيخليه الاول مثلا لو عدد البيكسل فى العمود 200 هعلخى اول بيكسل الى هو ب صفر يبقى ب199والعمليه دى هكررها على كل بيكسل







        else if (method == 3) {
            Image tImg(img.height, img.width);
            for (int i = 0; i < img.width; ++i) {
                for (int j = 0; j < img.height; ++j) {
                    
                    
                    tImg(j, img.width - 1 - i, 0) = img(i, j, 0);
                   
                    
                    tImg(j, img.width - 1 - i, 1) = img(i, j, 1);
                    
                    
                    tImg(j, img.width - 1 - i, 2) = img(i, j, 2);
                }
            }
            img = tImg;
        }
    }


//ده عمتلتوا عكس ال 90

// ده تانى فلتر الى هى السادس فى البى دى اف الى قال عليه الدكتور





    void flipImage(Image& img) {
        int choice;
        cout << "1. Flip Horizontally " << endl;
        cout << "2. Flip Vertically " << endl;
        cout << "Enter your choise: "<< endl;
        cin >> choice;





        int width = img.width;
        int height = img.height;






        if (choice == 1) { 
         
            
            
            
            
            
            for (int i = 0; i < width / 2; ++i) {
               
                
                for (int j = 0; j < height; ++j) {
                    
                    
                    
                    
                    for (int c = 0; c < 3; ++c) {
                       
                        
                        
                        int temp = img(i, j, c);
                       
                        
                        
                        img(i, j, c) = img(width - 1 - i, j, c);
                       
                        
                        img(width - 1 - i, j, c) = temp;
                    }
                }
            }
           
            
            
            
            cout << " flipped horizontally " << endl;
        }
       
        
        
        
        //  الفلتر بتاع الفليب مقسم لفكرتين اما اعكس الصوره بشكل راسى او بشكل افقى ده بقدر اعمله انى اخلى اول بيكسل يبقى مكان اخر بيكسل و بعمل فور لوب عشان العمليه دى تتكرر على باقى البيكسل

        
        
        
        
        
        
        
        else if (choice == 2) { 
            
            
            
            for (int i = 0; i < width; ++i) {

                
                
                for (int j = 0; j < height / 2; ++j) {
                   
                    
                    
                    
                    
                    for (int c = 0; c < 3; ++c) {

                        int temp = img(i, j, c);
                        img(i, j, c) = img(i, height - 1 - j, c);
                        img(i, height - 1 - j, c) = temp;
                    }
                }
            }
            cout << " flipped vertically done " << endl;
        }
        else {
            cout << "num doesn't exist" << endl;
        }
    }














int main() {
    string image_name;
    cout << "write the name for image: ";
    cin >> image_name;

   
    //هنا عملت متغير عشان اخد من اليوزر اسم الصوره
    
    
    
    
    Image img;
   
    if (!img.loadNewImage(image_name)) {
        cout << "it is not loaded" << endl;
        return 1;
    }
    // الجزء ده مخصص عشان لو اليوزر كتب الاسم غلط او كتب اسم فايل مش موجود








    cout << " Image filter Menu " << endl;
    cout << "1. Grayscale Filter" << endl;
    cout << "2. flip" << endl;
    cout << "3.rotate filter" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose a filter: ";



    //هنا بعد ما بخلى اليوزر يكتب اسم الفايل و يكون فعلا موجود ببدا اعرضله منيو بالفلاتر الى موجوده بارقمها 



    int choice;
    cin >> choice;




    // هنا بيبدا يختار الفلتر بالرقم بتاعه



    switch (choice) {
    case 1:
        Grayscale(img);
        cout << "Grayscale successfully.\n";
        break;

    case 2:
        flipImage(img);
        cout << "flip done. " << endl;
        break;
    
    case 3:
        rotateImage(img);
        
        cout << "retate done" << endl;
        break;



    case 4:
        cout << "Exiting program." << endl;
        return 0;
    
    
    
    default:
        cout << "Invalid choice." << endl;
        return 1;
    }

    // هنا ببدا اترجم اختيار اليوزه للخدمه الى هو طلبهاswitchده بقا جزء ال



    string output_name;
    cout << "\n write the new name : ";
    cin >> output_name;

    // فى الجزء ده بطلب من اليوزر يكتب اسم الفايل الجديد



    img.saveImage(output_name);
    cout << "Image saved successfully as: " << output_name << endl;
    // الخطوه النهاءيه هنا بيطلع الصوره المتفلتره لليوزر
    return 0;
}