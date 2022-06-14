/*
path1 - путь (с прямыми слэшами /) к файлу имён классов
path2 - путь (с прямыми слэшами /) к файлу конфигурации
path3 - путь (с прямыми слэшами /) к файлу весов
path4 - путь (с прямыми слэшами /) к фото (любого размера)
path5 - путь (с прямыми слэшами /) к видео

Для работы с видео раскомментировать "Видео" и закомментить "Фото"

*/

#include <Header.h>



int main()
{
    std::string path1,path2,path3,path4,path5,path6;
    path1 = "C:/Users/nikit/Desktop/Trained_nets/20feb/brig.names";
    path2 = "C:/Users/nikit/Desktop/Trained_nets/rgb/yolov4_rgb.cfg";
    path3 = "C:/Users/nikit/Desktop/Trained_nets/rgb/yolov4_rgb.weights";
    //path4 = "C:/Users/SaSha/Documents/Samples/Check_photos/182201_3812_1min4sec.jpg";
    path4 = "C:/Users/nikit/Desktop/Trained_nets/100720_163646_105_0min2sec.jpg";
    path5 = "D:/Work/Бриг/310522/ir3raw.mp4";
    path6 = "http://192.168.31.133:8080/video";

    RunYOLOonCPU Net;
    
    /*Получение имён классов из файла*/
    std::vector<std::string> labels;
    labels = Net.get_labels(path1);
    
    /*Загрузка модели в оперативную память*/
    bool gpu_run = 1;
    auto model = Net.load_model(path2, path3, gpu_run);

    int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
    VideoWriter writer("ir1finished.avi", codec, 30, Size(640,512));

    /*Вызов функции для инференса в режиме фото или видео*/

    /*Фото*/
        
//   float nms_thresh = 0.1;
//    float conf_thresh = 0.1;
//    bool show_output = 0;
   

//    cv::Mat frame = cv::imread(path4);

//    auto output = Net.get_prediction(
//        frame,
//        &model,
//        labels,
//        nms_thresh,
//        conf_thresh,
//        show_output);

//    auto [image, number_of_objects,box] = output;


//    cout << "There are " << number_of_objects << " object(s) in frame" << endl;
//    if (number_of_objects > 0)
//    {
//        std::cout << "[width] x [height] from (center_hor, center_ver): " << box[0] << "\n";
//    }
//    imshow("Display window", image);

    
//    int k = waitKey(0);
    
    /*Видео*/ 

//    cv::VideoCapture source("udpsrc port=5004 ! application/x-rtp,payload=96,encoding-name=H264 ! rtpjitterbuffer mode=1 ! rtph264depay ! h264parse ! decodebin ! videoconvert ! appsink", cv::CAP_GSTREAMER);
//    cv::VideoCapture source("udpsrc port=5004 ! application/x-rtp,payload=96,encoding-name=H264 ! rtph264depay ! h264parse ! decodebin ! videoconvert ! appsink", cv::CAP_GSTREAMER);
//    cv::VideoCapture source("udpsrc port=38000 ! application/x-rtp,payload=96,encoding-name=H264 ! rtph264depay ! h264parse ! avdec_h264 ! videoconvert ! appsink", cv::CAP_GSTREAMER);
    cv::VideoCapture source(path5);
    cv::Mat frame;

   

    float nms_thresh = 0.1;
    float conf_thresh = 0.6;
    bool show_output = 0;
    std::cout << cv::getBuildInformation();
    cv::waitKey();

    while (cv::waitKey(1) < 1)
    {
        source >> frame;
//        std::cout << cv::getBuildInformation();
        if (frame.empty())
        {
            cv::waitKey();
            break;
        }
//        auto start = std::chrono::steady_clock::now();

//        auto output = Net.get_prediction(
//            frame,
//            &model,
//            labels,
//            nms_thresh,
//            conf_thresh,
//            show_output);
        
//        auto [image, number_of_objects, box] = output;


        cv::line(frame, cv::Point(305,256), cv::Point(335,256), CV_RGB(255,0,0), 1, 8);
        cv::line(frame, cv::Point(320,241), cv::Point(320,271), CV_RGB(255,0,0), 1, 8);
        cv::circle(frame, cv::Point(320,256), 11, CV_RGB(0,255,0), 1, 8);
        cv::circle(frame, cv::Point(320,256), 30, CV_RGB(0,255,0), 1, 8);
        
//        auto end = std::chrono::steady_clock::now();
//        float total_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

//        cout << "There is (are) " << number_of_objects << " object(s) in frame." << " Frame time: " << total_time << " ms" <<endl;
//        if (number_of_objects > 0)
//        {
//            std::cout << "[width] x [height] from (center_hor, center_ver): " << box[0] << "\n";
//        }
        writer.write(frame);
//        if (frame.empty())
//        {
//            cv::waitKey();
//        }
//        else
//        {
//            imshow("Display window", frame);
//        }
        imshow("Display window", frame);
        
//        std::cout << typeid(image).name() << std::endl;
    }
    
    return 0;
}
