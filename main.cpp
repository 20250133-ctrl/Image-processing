/*
===================================================================================
FCAI – CS213 Object Oriented Programming – 2026 – Assignment 1 – Part 2
Program Name: Image Processing Console Application
Program Description: C++ Console Application for applying 16 image filters.

a) Team Details and IDs:
   1. Bishoy Kamel Edwar Hanna  | ID: 20250133 | Section: S21, S22
   2. Fady Mokbel Zaghloul      | ID: 20250460 | Section: S3, S4
   3. Kerolos Medhat Haleem     | ID: 20251301 | Section: S3, S4
   4. Felopater Ashraf Waseem   | ID: 20251288 | Section: S3, S4

b) Work Breakdown:
   - Menu System, File Loading/Saving & Overall Integration: Beshoy Kamel
   - Beshoy Kamel   : Filter 1 (Grayscale), Filter 5 (Flip), Filter 9 (Merge), Filter 13 (Sunlight)
   - Fady Mokbel    : Filter 6 (Rotate), Filter 2 (Black & White), Filter 10 (Image_Edges), Filter 15 (old_television_effect).
   - Kerolos Medhat : Filter 4 (Frame), Filter 8 (Resize), Filter 16 (Infrared), Filter 12 (Blur).
   - Felopater Ashraf: Filter 3 (Invert), Filter 7 (Darken/Lighten), Filter 11 (Crop), Filter 15 (Purple).
   - Filter 17 (oilPainting),Filter 18 (skewimage): ALL TEAM



c) Link to the Video Demo:
                          [حط هنا لينك فيديو الشرح اللي هتصوره على Drive أو YouTube]


d) Link to the Shared Document:
                               [حط هنا لينك المستند المشترك Google Doc]
===================================================================================
*/




//=====================================================================================================================================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include "Image_Class.h"
using namespace std;
// اول خطوه شغلنا المكاتب الى هنستخدمها و مكاتب دكتور الرملى و عشان هى بتتصنف كمكاتب محليه عملتهاب ""
//==================================================================================================================================================

//----------------------------------------------------------------------------------------------------------------------------------------------

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


// فلتر 1
// بيشوى

//-----------------------------------------------------------------------------------------------------------------------------------------------

void flipImage(Image& img) {
    int choice;
    cout << "1. Flip Horizontally " << endl;
    cout << "2. Flip Vertically " << endl;
    cout << "Enter your choise: " << endl;
    cin >> choice;

    // هبداء اول خطوه اشوف اليوزر عايز انهى فلتر



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
// فكره الكود هتعامل معاه اكنه مرايه هحط زى خط فى النص و البيكسل بغير مكانها بالبيكسل الى قمها الناحيه التانيه

// فلتر 5
// بيشوى
//-----------------------------------------------------------------------------------------------------------------------------------------------

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

//FADY
//-------------------------------------------------------------------------------------------------------------------------------------------------



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


// FADY

//-----------------------------------------------------------------------------------------------------------------------------------------------------


void frameImage(Image& img) {


    int choice;


    cout << "1. simple frame\n";


    cout << "2. fancy frame\n";


    cout << "choose frame type: ";


    cin >> choice;




    int r = 0, g = 0, b = 0;


    int color;


    cout << "1. red\n";


    cout << "2. green\n";


    cout << "3. blue\n";


    cout << "4. white\n";


    cout << "5. black\n";


    cout << "choose color: ";


    cin >> color;




    if (color == 1) { r = 255; g = 0; b = 0; }


    else if (color == 2) { r = 0; g = 255; b = 0; }


    else if (color == 3) { r = 0; g = 0; b = 255; }


    else if (color == 4) { r = 255; g = 255; b = 255; }


    else if (color == 5) { r = 0; g = 0; b = 0; }




    int frame_size = img.width / 20;




    if (choice == 1) {


        for (int i = 0; i < img.width; ++i) {


            for (int j = 0; j < img.height; ++j) {




                if (i < frame_size || i >= img.width - frame_size || j < frame_size || j >= img.height - frame_size) {




                    img(i, j, 0) = r;


                    img(i, j, 1) = g;


                    img(i, j, 2) = b;


                }


            }


        }


    }


    // هنا الفلتر بتاع الاطار البسيط بنحدد سمك الاطار وبنلف باللوب على الحواف ونغير لون البيكسل للون الي اليوزر اختاره




    else if (choice == 2) {


        for (int i = 0; i < img.width; ++i) {


            for (int j = 0; j < img.height; ++j) {




                if (i < frame_size || i >= img.width - frame_size || j < frame_size || j >= img.height - frame_size) {




                    if ((i / 12 + j / 12) % 2 == 0) {




                        img(i, j, 0) = 255;


                        img(i, j, 1) = 255;


                        img(i, j, 2) = 255;


                    }


                    else {




                        img(i, j, 0) = r;


                        img(i, j, 1) = g;


                        img(i, j, 2) = b;


                    }


                }


            }


        }


    }


    // هنا الاطار المزخرف عملت فكرة شطرنجية زغرفية بسيطة بتقسيم البيكسلات لنقط بيضا ونقط بلون الاطار عشان يبان شكل زخرفة واضح جداً ومختلف عن البسيط




}

// kerolos

//-----------------------------------------------------------------------------------------------------------------------------------------------


void resizeImage(Image& img) {


    int new_w, new_h;


    cout << "enter new width: ";


    cin >> new_w;




    cout << "enter new height: ";


    cin >> new_h;




    Image tImg(new_w, new_h);




    for (int i = 0; i < new_w; ++i) {


        for (int j = 0; j < new_h; ++j) {




            int old_i = (i * img.width) / new_w;


            int old_j = (j * img.height) / new_h;




            tImg(i, j, 0) = img(old_i, old_j, 0);


            tImg(i, j, 1) = img(old_i, old_j, 1);


            tImg(i, j, 2) = img(old_i, old_j, 2);


        }


    }




    img = tImg;


}


// هنا بناخد العرض والطول الجديد من اليوزر وبنعمل صورة جديدة موقتة ونعمل لوب على العرض والطول الجديد


// وبنسبة وتناسب بنجيب مكان البيكسل القديم وننسخ الالوان التلاتة الاحمر والاخضر والازرق

// kerolos

//---------------------------------------------------------------------------------------------------------------------------------------------------------
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

// Felopater
//-------------------------------------------------------------------------------------------------------------------------------------------------------

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

// Felopater
//----------------------------------------------------------------------------------------------------------------------------------------------------------
void merge_image(Image& img) {

    string imagefile2;
    cout << "enter the name" << endl;
    cin >> imagefile2;
    Image img2(imagefile2);
    // الفلتر ده الغرض منه ادمج صورتين ببعض  فاول خطوه احتاجت انى اخلى اليوزر يبدا يدخل الصوره التانيه من جوا الفانكشن نفسها عشان ميحصلش لخبطه فى باقى البرنامج



    if (img.width == img2.width && img.height == img2.height) {
        for (int i = 0; i < img.width; ++i) {
            for (int j = 0; j < img.height; ++j) {
                for (int c = 0; c < 3; ++c) {
                    img(i, j, c) = (img(i, j, c) + img2(i, j, c)) / 2;
                }
            }
        }
        // لو الشرط اتحقق و الصورتين قد بعض بالظبط يبقى هبدا اللف على البيكسل بالنيستد لوب و اخد الالوان بتاعت البسكسل فى الصورتين و اقسهمه على 2 

    }
    else {

        int your_choice;
        cout << "1. Resize to max" << endl;
        cout << "2. common area " << endl;
        cout << "Enter your choice (1 or 2): ";
        cin >> your_choice;
        if (your_choice == 1) {

            int maxwidth = max(img.width, img2.width);
            int maxheight = max(img.height, img2.height);




            Image newmax(maxwidth, maxheight);





            for (int i = 0; i < maxwidth; ++i) {

                for (int j = 0; j < maxheight; ++j) {
                    int x1 = i * img.width / maxwidth;
                    int y1 = j * img.height / maxheight;

                    int x2 = i * img2.width / maxwidth;
                    int y2 = j * img2.height / maxheight;

                    // هنا بعمل جزء من الفلتر الى عامله كيرلس انى بجيب ال مكان البيكسل الى عايزه من الصوره الاصليه عن طريق المعادله انى بضرب مكان البيكسل الجديد فى مكان البيكسل القديم و بقسم على الطول او العرض الاكبر

                    for (int c = 0; c < 3; ++c) {
                        newmax(i, j, c) = (img(x1, y1, c) + img2(x2, y2, c)) / 2;
                    }
                }
            }


            img = newmax;


        }
        else if (your_choice == 2) {

            int themin_width = min(img.width, img2.width);
            int themin_height = min(img.height, img2.height);
            // لو اختار ان نشتغل على االجزء المشترك بس بنشوف اصغر طول و اصغر عرض بنلف غليهم بالفورلوب عشان اللوب متضربش

            Image newmin(themin_width, themin_height);



            for (int i = 0; i < themin_width; ++i) {

                for (int j = 0; j < themin_height; ++j) {


                    for (int c = 0; c < 3; ++c) {


                        newmin(i, j, c) = (img(i, j, c) + img2(i, j, c)) / 2;
                    }
                }

                // بعد ما سويبنا الصورتين بالابعاد الاصغر نبدا ندمجهم 



                img = newmin;


            }
        }


    }













}

// بيشوى
// فلتر 9




//-------------------------------------------------------------------------------------------------------------------
void natural_sunlight(Image& img) {
    for (int i = 0; i < img.width; ++i) {
        for (int j = 0; j < img.height; ++j) {


            int red = img(i, j, 0);
            int green = img(i, j, 1);
            int blue = img(i, j, 2);


            red += 40;
            green += 20;
            blue -= 30;
            //عشان اعرف هنقص او ازود قد اى من كل لون aiانا خدت مساعده من ال 

            img(i, j, 0) = clamp(red, 0, 255);
            img(i, j, 1) = clamp(green, 0, 255);
            img(i, j, 2) = clamp(blue, 0, 255);
        }
        // clamp هنا استعملتها عشان احدد القيم بين 0 و255

    }

}


// الفلتر ده هنزود اللون الاحمر و الاخضر فى البيكسل عشان نقرب للون الاصفر للشمس و قللنا الازرق عشان نزود الدفء فى الصوره


// بيشوى 
//فلتر 13

//--------------------------------------------------------------------------------------------------------------------

// فلتر التغبيش بلور
void blurimage(Image& img) {

    // رقم البلور من اليوزر
    int r;
    cout << "enter blur radius: ";
    cin >> r;

    // لو اليوزر دخل رقم بالسالب اطلبه تاني عشان الميموري
    while (r < 0) {
        cout << "invalid radius, enter positive number: ";
        cin >> r;
    }

    int w = img.width;
    int h = img.height;

    // مصفوفة البريفكس سم التراكمية
    long long** arr = new long long* [w + 1];
    for (int i = 0; i <= w; ++i) {
        arr[i] = new long long[h + 1]();
    }

    // بنعدي على الالوان التلاتة
    for (int c = 0; c < 3; ++c) {

        // بنجمع قيم البيكسلات التراكمية
        for (int i = 1; i <= w; ++i) {
            for (int j = 1; j <= h; ++j) {
                arr[i][j] = (long long)img(i - 1, j - 1, c) + arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            }
        }

        // بنحسب المتوسط لكل بيكسل
        for (int j = 0; j < h; ++j) {
            for (int i = 0; i < w; ++i) {

                int x1 = max(0, i - r);
                int y1 = max(0, j - r);
                int x2 = min(w - 1, i + r);
                int y2 = min(h - 1, j + r);

                int a = (x2 - x1 + 1) * (y2 - y1 + 1);

                long long s = arr[x2 + 1][y2 + 1] - arr[x1][y2 + 1] - arr[x2 + 1][y1] + arr[x1][y1];

                img(i, j, c) = s / a;
            }
        }
    }

    // بنمسح الميموري اللي حجزناها
    for (int i = 0; i <= w; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    cout << "blur filter applied successfully" << endl;
}


//kerolos
//-----------------------------------------------------------------------------------------------------------------------

// فلتر الانفراريد
void infraredfilter(Image& img) {

    // بنلف على كل نقطة في الصورة
    for (int x = 0; x < img.width; ++x) {
        for (int y = 0; y < img.height; ++y) {

            // اللون الاحمر بنثبته ع الآخر
            img(x, y, 0) = 255;

            // وبنعكس اللونين التانيين
            img(x, y, 1) = 255 - img(x, y, 1);
            img(x, y, 2) = 255 - img(x, y, 2);
        }
    }

    cout << "infrared filter applied successfully" << endl;
}

//kerolos
//-----------------------------------------------------------------------------------------------------------------------------
// فلتر ميل الصورة
void skewimage(Image& img) {

    // الدرجة بتاعة الزاوية من اليوزر
    double deg;
    cout << "enter skew angle in degrees: ";
    cin >> deg;

    // تحويل للراديان عشان دالة التان
    double rd = deg * 3.14159 / 180.0;

    int w = img.width;
    int h = img.height;

    // الزيادة في العرض
    int sh = h * tan(rd);

    int nw = w + sh;

    // صورة جديدة مؤقتة
    Image temp(nw, h);

    // بنخلي خلفية الصورة بيضا
    for (int x = 0; x < nw; ++x) {
        for (int y = 0; y < h; ++y) {
            temp(x, y, 0) = 255;
            temp(x, y, 1) = 255;
            temp(x, y, 2) = 255;
        }
    }

    // تشفيت الصفوف
    for (int y = 0; y < h; ++y) {

        int off = (h - 1 - y) * tan(rd);

        for (int x = 0; x < w; ++x) {
            temp(x + off, y, 0) = img(x, y, 0);
            temp(x + off, y, 1) = img(x, y, 1);
            temp(x + off, y, 2) = img(x, y, 2);
        }
    }

    img = temp;

    cout << "skew filter applied successfully" << endl;
}
//kerolos
//-----------------------------------------------------------------------------------------------------------------------------
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
//فيلوباتير
//----------------------------------------------------------------------------------------
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
//فيلوباتير
// ---------------------------------------------------------------------------------------

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
// ---------------------------------------------------------------------------------------
void old_television_effect(Image& img) {

    for (int i = 0; i < img.width; ++i) {

        for (int j = 0; j < img.height; ++j) {
            if (j % 2 == 0) {
                img(i, j, 0) = img(i, j, 0) * .5;
                img(i, j, 1) = img(i, j, 1) * .5;
                img(i, j, 2) = img(i, j, 2) * .5;
            }
        }
    }
}

// جيبت كل بيكسل بيقبل القسمة على اتنين و غمقت لونه بضرب كل لون في البكسل في نص 
// ---------------------------------------------------------------------------------------
// بدايه كود فلتر 10
void Image_Edges(Image& img) {

    for (int i = 0; i < img.width; ++i) {

        for (int j = 0; j < img.height; ++j) {
            int r = img(i, j, 0);
            int g = img(i, j, 1);
            int b = img(i, j, 2);

            int r2 = img(i + 1, j, 0);
            int g2 = img(i + 1, j, 1);
            int b2 = img(i + 1, j, 2);

            int diff = abs(r - r2) + abs(g - g2) + abs(b - b2);

            if (diff > 50) {
                img(i, j, 0) = 0;
                img(i, j, 1) = 0;
                img(i, j, 2) = 0;
            }
            else {
                img(i, j, 0) = 255;
                img(i, j, 1) = 255;
                img(i, j, 2) = 255;
            }
        }
    }
}
//عشان اجيب الحواف كان لازم افرق بين الالوان بين كل بكسل و اللي بعده
// عشان لو في تغير كبير في اللون هنعرف ان دي حافه


// ---------------------------------------------------------------------------------------
//==========================================================================================================================
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
    cout << "4. black_white" << endl;
    cout << "5. frameImage" << endl;
    cout << "6. resizeImage" << endl;
    cout << "7. invertImage " << endl;
    cout << "8.darken_lighten " << endl;
    cout << "9.merge_image" << endl;
    cout << "10.natural_sunlight" << endl;
    cout << "11. infraredfilter" << endl;
    cout << "12. blurimage Filter" << endl;
    cout << "13. skewimage Filter" << endl;
    cout << "14. cropImage Filter" << endl;
    cout << "15. purpleFilter Filter" << endl;
    cout << "16. oilPainting Filter" << endl;
    cout << "17. Image_Edges Filter" << endl;
    cout << "18. old_television_effect Filter" << endl;
    cout << "19. Exit" << endl;
    cout << "Choose a filter: ";



    //هنا بعد ما بخلى اليوزر يكتب اسم الفايل و يكون فعلا موجود ببدا اعرضله منيو بالفلاتر الى موجوده بارقمها 



    int choice;
    cin >> choice;




    // هنا بيبدا يختار الفلتر بالرقم بتاعه



    switch (choice) {
    case 1:
        Grayscale(img);
        cout << "Grayscale successfully." << endl;
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
        black_white(img);

        cout << " black_white done" << endl;
        break;

    case 5:
        frameImage(img);

        cout << "frameImage done" << endl;
        break;

    case 6:
        resizeImage(img);

        cout << "resize done" << endl;

        break;

    case 7:
        invertImage(img);

        cout << "invertImage done" << endl;

        break;



    case 8:
        darken_lighten(img);

        cout << "darken_lighten done" << endl;

        break;




    case 9:
        merge_image(img);

        cout << "merge_image done" << endl;

        break;



    case 10:
        natural_sunlight(img);

        cout << "natural_sunlight done" << endl;

        break;


    case 11:
        infraredfilter(img);
        cout << "infraredfilter successfully" << endl;
        break;



    case 12:
        blurimage(img);
        cout << "blurimage successfully" << endl;
        break;



    case 13:
        skewimage(img);
        cout << "skewimage successfully" << endl;
        break;



    case 14:
        cropImage(img);
        cout << "cropImage successfully" << endl;
        break;




    case 15:
        purpleFilter(img);
        cout << "purpleFilter successfully." << endl;
        break;


    case 16:
        oilPainting(img);
        cout << "oilPainting successfully." << endl;
        break;

    case 17:
        Image_Edges(img);
        cout << "Image_Edges successfully." << endl;
        break;



    case 18:
        old_television_effect(img);
        cout << "old_television_effect successfully." << endl;
        break;



    case 19:
        cout << "Exiting program." << endl;
        return 0;





    default:
        cout << "Invalid choice." << endl;
        return 1;
    }

    // هنا ببدا اترجم اختيار اليوزه للخدمه الى هو طلبهاswitchده بقا جزء ال
    // بكتب فيها اسم الفانكشن الى اليوزر اختارها فالصوره بيبدا يتعمل عليها التعديل على حسب اليوزر اختار اى



    string output_name;
    cout << "\n write the new name : ";
    cin >> output_name;

    // فى الجزء ده بطلب من اليوزر يكتب اسم الفايل الجديد



    img.saveImage(output_name);
    cout << "Image saved successfully as: " << output_name << endl;
    // الخطوه النهاءيه هنا بيطلع الصوره المتفلتره لليوزر
    return 0;
}