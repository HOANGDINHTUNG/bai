//
// Created by HOANG DINH TUNG on 1/10/2025.
//

#ifndef UNTITLED4_STRUCT_H
#define UNTITLED4_STRUCT_H
#include<stdbool.h>
struct Student{
    char id[6];
    char name[25];
    char sex[5];
    char phoneNumber[11];
    char email[20];
    char birthday[15];
    char address[50];
    char class[20];
    int status; //trang thai 0/1/2/3/4/5 tuong ứng dang hoc/bo hoc/tot nghiep/tot nghiep som/bao luu/dinh chi
};
typedef struct Student Student;
struct Class{
    char id[6];
    char name[20];
    char majors[30];//nganh hoc
    Student  list[40];
    int size;//si so lop
    int status;//trang thai lop hoc 0/1/2 tuong ung voi dang cho/ dang học/ da ket thuc
};
typedef  struct Class Class;
Class c1={"C3658","bo tuc","toan cao cap",40,1};
Class c2={"5938D","hoc them","tieng phap",24,2};
Class c3={"K890I","nang cao","giai tich",30,1};
Class c4={"HJ678","hoc dui","tich phan",14,0};
#endif //UNTITLED4_STRUCT_H
