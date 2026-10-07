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




void flipImage(Image& img) {
    int choice;
    cout << "1. Flip Horizontally " << endl;
    cout << "2. Flip Vertically " << endl;
    cout << "Enter your choise: " << endl;
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



void black_white(Image& img) {

    for (int i = 0; i < img.width; ++i) {

        for (int j = 0; j < img.height; ++j) {

            int avg = (img(i, j, 0) + img(i, j, 1) + img(i, j, 2)) / 3;

            if (avg > 128)
            {
                img(i, j, 0) = 255;
                img(i, j, 1) = 255;
                img(i, j, 2) = 255;
            }
            else
            {
                img(i, j, 0) = 0;
                img(i, j, 1) = 0;
                img(i, j, 2) = 0;
            }
        }
    }
}

// هنا بيقرا كل بيكسل و يحسب المتوسط بتاعه لو المتوسط ده اكبر من 128 يبقى البيكسل ده هيبقى ابيض و لو اقل يبقى اسود



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


/*

ده كود الفلاتر المطلوبة: 3 و 7 و 11 و 15 و 18

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





// بدايه كود فلتر 11

void cropImage(Image& img) {
    int x, y, W, H;

    cout << "Enter starting point x: ";
    cin >> x;
    cout << "Enter starting point y: ";
    cin >> y;

    cout << "Enter width (W): ";
    cin >> W;
    cout << "Enter height (H): ";
    cin >> H;


    int corrected_y = img.height - y - H;

    if (x < 0 || corrected_y < 0 || x + W > img.width || corrected_y + H > img.height) {
        cout << "Invalid dimensions! Out of bounds." << endl;
        return;
    }

    Image croppedImg(W, H);

    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < H; ++j) {
            for (int c = 0; c < 3; ++c) {
                croppedImg(i, j, c) = img(x + i, corrected_y + j, c);
            }
        }
    }

    img = croppedImg;
}

// نهايه كود فلتر 11





// بدايه كود فلتر 15

void purpleFilter(Image& img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {

            // زيادة اللون الأحمر والأزرق وتقليل الأخضر عشان يدي تأثير اللون البنفسجي  
            int r = img(i, j, 0) + 50;
            int g = img(i, j, 1) - 30;
            int b = img(i, j, 2) + 50;

            if (r > 255) r = 255;
            if (g < 0) g = 0;
            if (b > 255) b = 255;

            img(i, j, 0) = r;
            img(i, j, 1) = g;
            img(i, j, 2) = b;
        }
    }
}

// نهايه كود فلتر 15





// بدايه كود فلتر 18

void oilPainting(Image& img) {
    int radius = 3;
    int levels = 20;
    Image tImg(img.width, img.height);

    for (int x = 0; x < img.width; ++x) {
        for (int y = 0; y < img.height; ++y) {

            int intensityCount[20] = { 0 };
            int sumR[20] = { 0 };
            int sumG[20] = { 0 };
            int sumB[20] = { 0 };

            for (int dx = -radius; dx <= radius; ++dx) {
                for (int dy = -radius; dy <= radius; ++dy) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < img.width && ny >= 0 && ny < img.height) {
                        int r = img(nx, ny, 0);
                        int g = img(nx, ny, 1);
                        int b = img(nx, ny, 2);

                        int curIntensity = ((r + g + b) / 3.0) * (levels - 1) / 255.0;

                        intensityCount[curIntensity]++;
                        sumR[curIntensity] += r;
                        sumG[curIntensity] += g;
                        sumB[curIntensity] += b;
                    }
                }
            }

            int maxCount = 0;
            int maxIndex = 0;
            for (int k = 0; k < levels; ++k) {
                if (intensityCount[k] > maxCount) {
                    maxCount = intensityCount[k];
                    maxIndex = k;
                }
            }

            tImg(x, y, 0) = sumR[maxIndex] / maxCount;
            tImg(x, y, 1) = sumG[maxIndex] / maxCount;
            tImg(x, y, 2) = sumB[maxIndex] / maxCount;
        }
    }
    img = tImg;
}
// فلتر رقم 18 الخاص بتأثير الرسم بالزيت Oil Painting عبر حساب متوسط الألوان الأكثر تكراراً في البيكسلات المجاورة
// نهايه كود فلتر 18





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
    cout << "3. black_white" << endl;
    cout << "4. rotateImage" << endl;
    cout << "5. Invert Image" << endl;
    cout << "7. Darken / Lighten Image" << endl;
    cout << "11. Crop Image" << endl;
    cout << "15. Purple Filter" << endl;
    cout << "18. Oil Painting" << endl;
    cout << "0. Exit" << endl;
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
        black_white(img);

        cout << "color done" << endl;
        break;

    case 4:
        rotateImage(img);

        cout << "retate done" << endl;
        break;

    case 5:
        invertImage(img);
        cout << "invert done. " << endl;
        break;

    case 7:
        darken_lighten(img);
        cout << "darken/lighten done. " << endl;
        break;

    case 11:
        cropImage(img);
        cout << "Crop done." << endl;
        break;

    case 15:
        purpleFilter(img);
        cout << "Purple Filter done." << endl;
        break;

    case 18:
        oilPainting(img);
        cout << "Oil Painting done." << endl;
        break;

    case 0:
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