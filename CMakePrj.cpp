// CMakePrj.cpp: определяет точку входа для приложения.
//

#include "CMakePrj.h"
#include "Header1.h"
using namespace std;

int main()
{
    // Создание объекта Json::Value
    Json::Value root;

    // Заполнение объекта Json::Value данными
    root["name"] = "John Doe";
    root["age"] = 30;
    root["city"] = "New York";

    // Преобразование объекта Json::Value в строку JSON
    Json::StyledWriter writer;
    std::string jsonString = writer.write(root);

    // Запись строки JSON в файл
    std::ofstream outputFile("output.json");
    if (outputFile.is_open()) {
        outputFile << jsonString;
        outputFile.close();
        std::cout << "JSON файл успешно записан." << std::endl;
    }
    else {
        std::cout << "Ошибка при открытии файла." << std::endl;
    }

    return 0;
}
