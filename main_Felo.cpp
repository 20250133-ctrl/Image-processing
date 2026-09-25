#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include "Image_Class.h"
using namespace std;

/*

ده كود فلتر 3 و 7 

======================================
Name: Felopateer Ashraf   ID:20251288
======================================

*/


// بدايه كود فلتر 3 


void invertImage(Image& img) {




    for (int i = 0; i < img.width; ++i) {


        for (int j = 0; j < img.height; ++j) {




            for (int p = 0; p < 3; ++p) {

                img(i, j, p) = 255 - img(i, j, p);
            }
        }
    }
}
// ده فلتر عكس الالوان بيعمل تاثير النيجاتيف
// بنلف على كل بيكسل و نطرح قيمة كل لون من ال 255 عشان الفاتح يبقى غامق و العكس
// نهايه كود فلتر 3





// بدايه كود فلتر 7 

void darken_lighten(Image& img) {
    int choice;
    cout << "1. Lighten image (50%)" << endl;
    cout << "2. Darken image (50%)" << endl;
    cout << "Enter your choise: " << endl;
    cin >> choice;





    if (choice == 1) {






        for (int i = 0; i < img.width; ++i) {


            for (int j = 0; j < img.height; ++j) {




                for (int c = 0; c < 3; ++c) {

                    img(i, j, c) = img(i, j, c) + (255 - img(i, j, c)) * 0.5;
                }
            }
        }




        cout << " lightened done " << endl;
    }




    // فى التفتيح بنزود نص المسافة الباقية لحد ال 255 لكل لون فى البيكسل عشان الصورة تفتح بنسبة 50%








    else if (choice == 2) {



        for (int i = 0; i < img.width; ++i) {



            for (int j = 0; j < img.height; ++j) {





                for (int c = 0; c < 3; ++c) {

                    img(i, j, c) = img(i, j, c) * 0.5;
                }
            }
        }
        cout << " darkened done " << endl;
    }
    // فى التغميق بنضرب كل لون فى نص عشان شدة الاضاءة تقل للنص


    else {
        cout << "num doesn't exist" << endl;
    }
}


// نهايه كود فلتر 7



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
    cout << "1. Invert Image" << endl;
    cout << "2. Darken / Lighten Image" << endl;
    cout << "3. Exit" << endl;
    cout << "Choose a filter: ";



    //هنا بعد ما بخلى اليوزر يكتب اسم الفايل و يكون فعلا موجود ببدا اعرضله منيو بالفلاتر الى موجوده بارقمها 



    int choice;
    cin >> choice;




    // هنا بيبدا يختار الفلتر بالرقم بتاعه



    switch (choice) {
    case 1:
        invertImage(img);
        cout << "invert done. " << endl;
        break;

    case 2:
        darken_lighten(img);
        cout << "darken/lighten done. " << endl;
        break;

    case 3:
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

