#include <opencv2/opencv.hpp>
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#elif __linux__
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#endif

cv::Mat takeScreenshot() {
    cv::Mat screenshot;

#ifdef _WIN32
    // Capture de l'écran sous Windows
    HDC hScreen = GetDC(NULL);
    HDC hDC = CreateCompatibleDC(hScreen);

    int width = GetSystemMetrics(SM_CXSCREEN);
    int height = GetSystemMetrics(SM_CYSCREEN);

    HBITMAP hBitmap = CreateCompatibleBitmap(hScreen, width, height);
    SelectObject(hDC, hBitmap);

    BitBlt(hDC, 0, 0, width, height, hScreen, 0, 0, SRCCOPY);

    BITMAPINFOHEADER bi = { sizeof(BITMAPINFOHEADER), width, -height, 1, 32, BI_RGB, 0, 0, 0, 0, 0 };
    std::vector<unsigned char> buffer(width * height * 4);
    GetDIBits(hDC, hBitmap, 0, height, buffer.data(), (BITMAPINFO*)&bi, DIB_RGB_COLORS);

    screenshot = cv::Mat(height, width, CV_8UC4, buffer.data()).clone();

    DeleteObject(hBitmap);
    DeleteDC(hDC);
    ReleaseDC(NULL, hScreen);

#elif __linux__
    // Capture de l'écran sous Linux
    Display* display = XOpenDisplay(NULL);
    if (!display) {
        std::cerr << "Erreur lors de l'ouverture de l'affichage X11" << std::endl;
        return cv::Mat();
    }

    Window root = DefaultRootWindow(display);
    XWindowAttributes gwa;
    XGetWindowAttributes(display, root, &gwa);
std::cout << "oui" << std::endl;
    int width = gwa.width;
    int height = gwa.height;
    // Capture de l'image en utilisant XGetImage
    XImage* img = XGetImage(display, root, 0, 0, width, height, AllPlanes, ZPixmap);
    if (!img) {
        std::cerr << "Erreur lors de la capture de l'écran X11" << std::endl;
        XCloseDisplay(display);
        return cv::Mat();
    }

    // Assurez-vous que les données de l'image sont en BGRA ou RGBA
    cv::Mat mat(height, width, CV_8UC4, img->data, img->bytes_per_line);
    cv::Mat converted;
    cv::cvtColor(mat, converted, cv::COLOR_BGRA2BGR); // Convertir de BGRA à BGR
std::cout << "oui" << std::endl;
    // Sauvegarder la capture avant de détruire l'image X11
    screenshot = converted.clone();

    //XDestroyImage(img);
	std::cout << "oui" << std::endl;
    XCloseDisplay(display);
#endif

    return screenshot;
}

int main() {
    cv::Mat screenshot = takeScreenshot();

    if (screenshot.empty()) {
        std::cerr << "Erreur lors de la capture de l'écran!" << std::endl;
        return -1;
    }

    cv::imshow("Capture d'écran", screenshot);
    cv::waitKey(0);

    cv::imwrite("screenshot.png", screenshot);
    std::cout << "Capture d'écran sauvegardée sous 'screenshot.png'" << std::endl;

    return 0;
}
