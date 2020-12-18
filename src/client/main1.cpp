#include <iostream>
#include "commands.hpp"
#include <cstring>
#include "manage.h"

using namespace std;

int main1(char *argv) {
    if (!strcmp(argv, "--help") || !strcmp(argv, "-h")) {
        cout << "Авторы: Дак Михаил, Лозовой Владислав, Степанов Владислав" << endl
             << "Программа предназначена для работы с файловой системой" << endl
             << "--help || -h Вывод информации о программе и её функциях" << endl
             << "--MV ./fileName.txt ./builds/fileName.txt - Перемещение файла в нужную директорию" << endl
             << "--CP ./fileName.txt ./builds/fileName.txt - Копирование файла в нужную директорию" << endl
             << "--ls ./directoryName - Отображение всех файлов в директории" << endl
             << "--RM ./fileName.txt - Удалить файл из текущей директории" << endl
             << "--SizeFile ./fileName.txt - Размер файла" << endl
             << "--SizeDir ./directoryName/ - Размер директории" << endl
             << "--procfs - Отображение всех процессов из файловой системы procfs" << endl;
    } else if (!strcmp(argv, "--MV")) {
        char *oldpath = new char[100];
        char *newpath = new char[100];
        cout << "Write old path: " << endl;
        cin >> oldpath;
        cout << "Write new path: " << endl;
        cin >> newpath;

        MV(oldpath, newpath);
    } else if (!strcmp(argv, "--CP")) {
        char *oldpath = new char[100];
        char *newpath = new char[100];
        cout << "Write old path: " << endl;
        cin >> oldpath;
        cout << "Write new path: " << endl;
        cin >> newpath;

        CP(oldpath, newpath);
    } else if (!strcmp(argv, "--RM")) {
        char *name = new char[100];
        cout << "Write old path: " << endl;
        cin >> name;

        RM(name);
    } else if (!strcmp(argv, "--SizeFile")) {
        char *name = new char[100];
        cout << "Write old path: " << endl;
        cin >> name;

        SizeFile(name);
    } else if (!strcmp(argv, "--SizeDir")) {
        char *name = new char[100];
        cout << "Write name of dir: " << endl;
        cin >> name;

        SizeDir(name);
    } else if (!strcmp(argv, "--ls")) {
        char *name = new char[100];
        cout << "Write name of dir: " << endl;
        cin >> name;

        ls(name);
    } else if (!strcmp(argv, "--procfs")) {
        mapping_process();
    }

    return 0;
}
