//
// Created by HOANG DINH TUNG on 1/10/2025.
//
#include "struct.h"
#include <string.h>
#include <stdlib.h>
#ifndef UNTITLED4_FUNCTION_H
#define UNTITLED4_FUNCTION_H
#define MAX 100
Class cla1[MAX];
Student stu[MAX];
int numClass=0;
int numStudent=0;

// trang thai lop hoc
char* statusClass(int n) {
    if(n==0){
        return "Dang cho";
    }
    else if(n==1){
        return "Dang hoc";
    }
    else if(n==2){
        return "Ket thuc";
    }
    return 0;
}

// trang thái sinh vien
char* statusStudent(int n){
    if(n==0){
        return "Dang hoc";
    }
    else if(n==1){
        return "Bo hoc";
    }
    else if(n==2){
        return "Tot nghiep";
    }
    else if(n==3){
        return "Tot nghiep som";
    }
    else if(n==4){
        return "Bao luu";
    }
    else if(n==5){
        return "Dinh chi";
    }
    return 0;
}

// hien thi menu chinh
void showMenuMain(){
    printf("|-------------------PTIT------------------|\n");
    printf("%-42s%-s\n","| 1.Quan ly lop hoc","|");
    printf("%-42s%-s\n","| 2.Quan ly sinh vien","|");
    printf("%-42s%-s\n","| 3.Thong ke","|");
    printf("%-42s%-s\n","| 0.Thoat","|");
    printf("|-----------------------------------------|\n");
}

// hien thi menu quan ly lop hoc
void showMenuClass(){
    printf("|-------------------CLASS-----------------|\n");
    printf("%-42s%-s\n","| 1.Xem danh sach lop hoc","|");
    printf("%-42s%-s\n","| 2.Them moi lop hoc","|");
    printf("%-42s%-s\n","| 3.Chinh sua thong tin lop hoc","|");
    printf("%-42s%-s\n","| 4.Xoa lop hoc","|");
    printf("%-42s%-s\n","| 0.Quay lai","|");
    printf("|-----------------------------------------|\n");
}

// hien thi menu quan ly sinh vien
void showMenuStudent(){
    printf("|-----------------STUDENT-----------------|\n");
    printf("%-42s%-s\n","| 1.Xem danh sach sinh vien","|");
    printf("%-42s%-s\n","| 2.Them moi sinh vien","|");
    printf("%-42s%-s\n","| 3.Chinh sua thong tin sinh vien","|");
    printf("%-42s%-s\n","| 4.Xem chi tiet thong tin sinh vien","|");
    printf("%-42s%-s\n","| 5.Xoa sinh vien","|");
    printf("%-42s%-s\n","| 0.Quay lai","|");
    printf("|-----------------------------------------|\n");
}

// nhap vao cac thong tin cua lop hoc
void inputInfoClass(Class *infor,int *i,int flap){
    fflush(stdin);
    if(flap==0){
        printf("Moi nhap vao vao ma so lop (vd: 36E) : ");
        fgets(infor[*i].id,sizeof(infor[*i].id),stdin);
        infor[*i].id[strcspn(infor[*i].id,"\n")]='\0';
    }
    printf("Moi nhap vao ten lop : ");
    fgets(infor[*i].name,sizeof(infor[*i].name),stdin);
    infor[*i].name[strcspn(infor[*i].name,"\n")]='\0';
    printf("Moi nhap vao chuyen nganh : ");
    fgets(infor[*i].majors,sizeof(infor[*i].majors),stdin);
    infor[*i].majors[strcspn(infor[*i].majors,"\n")]='\0';
    infor[*i].size=0;
    infor[*i].status=0;
    fflush(stdin);
    if(flap==1){
        do{
            printf("Moi nhap vao si so lop (<=40) : ");
            scanf("%d",&infor[*i].size);
        }while(infor[*i].size>40||infor[*i].size<0);
        do{
            printf("Moi nhap vao trang thai (0,1,2) : ");
            scanf("%d",&infor[*i].status);
        } while (infor[*i].status<0||infor[*i].status>2);
    }
    ++(*i);
}

// xem danh sach lop hoc
void showInfoClass(Class *infor,int number){
    printf("+--------+--------------------+----INFORMATION CLASS---------+----+---------------+\n");
    printf("|%-8s|%-20s|%-30s|%-4s|%-15s|\n","ID","NAME","MAJORS","SIZE","STATUS");
    printf("+--------+--------------------+------------------------------+----+---------------+\n");
    for(int i=0;i<number;i++){
        printf("|%-8s|%-20s|%-30s|%-4d|%-15s|\n" , infor[i].id , infor[i].name , infor[i].majors , infor[i].size, statusClass(infor[i].status));
        printf("+--------+--------------------+------------------------------+----+---------------+\n");
    }
}

// chinh sua danh sach lop hoc
void editInforClass(Class *infor,int number){
    showInfoClass(infor,number);
    char ma[8];//xau ma lop
    int flap=0;//bien dung de thong bao
    fflush(stdin);
    printf("Moi nhap vao ma lop muon chinh sua : ");
    fgets(ma,sizeof(ma),stdin);
    ma[strcspn(ma,"\n")]='\0';
    for(int i=0; i < number; i++){
        if(strcmp(infor[i].id,ma)==0){
            flap=1;
            inputInfoClass(infor, &i, 1);
            printf("Chinh sua THANH CONG!!!\n");
            break;
        }
    }
    if(!flap){
        printf("Khong tim thay ma lop!!!!\n");
    }
}

// xoa lop hoc
void deleteClass(Class *infor,int *number){
    int flap=0;
    char ma[8];
    fflush(stdin);
    printf("Moi nhap vao ma so lop de xoa : ");
    fgets(ma,sizeof(ma),stdin);
    ma[strcspn(ma,"\n")]='\0';
    for (int i = 0; i < *number; i++) {
        if (strcmp(infor[i].id, ma) == 0) {
            if (infor[i].size == 0) {//lop khong co hoc sinh
                for (int j = i; j < *number - 1; j++) {
                    *(infor + j) = *(infor + j + 1);
                }
                --(*number);
                flap=1;
                printf("Xoa THANH CONG!!!!!\n");
            } else {
                printf("Khong the xoa vi lop con sinh vien!!!\n");
                return;
            }
        }

    }
    if(!flap){
        printf("Ma so lop khong ton tai!!!\n");
    }
}

// lua chon tinh nang trong menu quan ly lop hoc
void choiceMenuClass() {
    while (1) {
        showMenuClass();
        int choice;
        printf("Moi nhap vao su lua chon cua ban : ");
        scanf("%d", &choice);
        switch (choice) {
            // hien thi thong tin cua cac lop hoc
            case 1: {
                if(numClass==0){
                    printf("Chua co lop hoc nao!!!!\n");
                    break;
                }
                else{
                    showInfoClass(cla1,numClass);
                }
                break;
            }
            // them moi 1 lop hoc
            case 2: {
                if(numClass==MAX) {
                    printf("Tong so luong lop hoc da day, khong the them!!!!!\n");
                    break;
                }
                inputInfoClass(cla1,&numClass,0);
                break;
            }
            // chinh sua thong tin cua 1 lop hoc
            case 3: {
                editInforClass(cla1,numClass);
                break;
            }
            // xoa 1 lop hoc
            case 4:{
                deleteClass(cla1,&numClass);
                break;
            }
            case 0: {
                break;
            }
            default:
                printf("Lua chon cua ban khong co trong menu!!!!\n");
                break;
        }
        if (choice == 0) {
            printf("Tro lai menu!!!\n");
            break;
        }
    }
}

// xem danh sach sinh vien
void showInforStudent(Student *infor,int number){
    printf("+--------+--------------------+-INFORMATION CLASS--+--------------------+---------------+\n");
    printf("|%-8s|%-20s|%-20s|%-20s|%-15s|\n","ID","NAME","BIRTHDAY","CLASS","STATUS");
    printf("+--------+--------------------+--------------------+--------------------+---------------+\n");
    for(int i=0;i<number;i++){
        printf("|%-8s|%-20s|%-20s|%-20s|%-15s|\n" , infor[i].id , infor[i].name ,infor[i].birthday ,infor[i].class,statusStudent(infor[i].status));
        printf("+--------+--------------------+----------------+--------------------+---------------+\n");
    }
}

// nhap id va xuat ra ten lop
char* findClass(char *findIdClass,Class listId[],int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(findIdClass, listId[i].id) == 0) {//neu id nhap ti thay trong id class dax cho
            return listId[i].name;
        }
    }
    return 0;
}

// nhap ma lop cho sinh vien
void inputIdClass(Student *class){
    char ma[8];
    printf("Moi nhap vao ma lop : ");
    fgets(ma,sizeof(ma),stdin);
    ma[strcspn(ma,"\n")]='\0';
    strcpy(class[numStudent].class,findClass(ma,cla1,numClass));
}

// nhap cac thong tin cua sinh vien
void inputInfoStudent(Student *infor,int *i,int flap){
    fflush(stdin);
    if(flap==0){
        printf("Moi nhap vao vao ma so sinh vien (vd: CN24) : ");
        fgets(infor[*i].id,sizeof(infor[*i].id),stdin);
        infor[*i].id[strcspn(infor[*i].id,"\n")]='\0';
    }
    printf("Moi nhap vao ten sinh vien : ");
    fgets(infor[*i].name,sizeof(infor[*i].name),stdin);
    infor[*i].name[strcspn(infor[*i].name,"\n")]='\0';
    fflush(stdin);
    printf("Moi nhap vao gioi tinh (nam hoac nu) : ");
    fgets(infor[*i].sex,sizeof(infor[*i].sex),stdin);
    infor[*i].sex[strcspn(infor[*i].sex,"\n")]='\0';
    fflush(stdin);
    printf("Moi nhap vao so dien thoai : ");
    fgets(infor[*i].phoneNumber,sizeof(infor[*i].phoneNumber),stdin);
    infor[*i].phoneNumber[strcspn(infor[*i].phoneNumber,"\n")]='\0';
    fflush(stdin);
    printf("Moi nhap vao email : ");
    fgets(infor[*i].email,sizeof(infor[*i].email),stdin);
    infor[*i].email[strcspn(infor[*i].email,"\n")]='\0';
    fflush(stdin);
    printf("Moi nhap vao ngay thang nam sinh (dd/mm/yyyy) : ");
    fgets(infor[*i].birthday,sizeof(infor[*i].birthday),stdin);
    infor[*i].birthday[strcspn(infor[*i].birthday,"\n")]='\0';
    fflush(stdin);
    printf("Moi nhap vao dia chi : ");
    fgets(infor[*i].address,sizeof(infor[*i].address),stdin);
    infor[*i].address[strcspn(infor[*i].address,"\n")]='\0';
    fflush(stdin);
    inputIdClass(infor);
    infor[*i].status=0;
    if(flap==1){
        do{
            printf("Moi nhap vao trang thai (0,1,2,3,4,5) : ");
            scanf("%d",&infor[*i].status);
        }while(infor[*i].status<0||infor[*i].status>5);
    }
    ++(*i);
}

// chinh sua thong tin sinh vien
void editInforStudent(Student *infor,int number){
    char ma[8];//xau ma sinh vien
    int flap=0;//bien dung de thong bao
    fflush(stdin);
    printf("Moi nhap vao ma sinh vien muon chinh sua : ");
    fgets(ma,sizeof(ma),stdin);
    ma[strcspn(ma,"\n")]='\0';
    for(int i=0; i < number; i++){
        if(strcmp(infor[i].id,ma)==0){
            flap=1;
            inputInfoStudent(infor, &i, 1);
            printf("Chinh sua THANH CONG!!!\n");
            break;
        }
    }
    if(flap==0){
        printf("Khong tim thay ma sinh vien!!!!\n");
    }
}

// xem thong tin chi tiet cua 1 sinh vien
void showDetailsInforStudent(Student *infor,int number){
    char ma[8];//xau ma sinh vien
    int flap=0;//bien dung de thong bao
    fflush(stdin);
    printf("Moi nhap vao ma sinh vien muon chinh sua : ");
    fgets(ma,sizeof(ma),stdin);
    ma[strcspn(ma,"\n")]='\0';
    for(int i=0; i < number; i++){
        if(strcmp(infor[i].id,ma)==0){
            flap=1;
            printf("Ma sinh vien la %s\n",infor[i].id);
            printf("Ho va ten la %s\n",infor[i].name);
            printf("Gioi tinh %s\n",infor[i].sex);
            printf("So dien thoai lien lac %s\n",infor[i].phoneNumber);
            printf("Dia chi email %s\n",infor[i].email);
            printf("Ngay thang nam sinh %s\n",infor[i].birthday);
            printf("Dia chi nha %s\n",infor[i].address);
            printf("Ten lop dang hoc %s\n",infor[i].class);
            printf("Trang thai hien tai %s\n", statusStudent(infor[i].status));
            break;
        }
    }
    if(flap==0){
        printf("Khong tim thay ma sinh vien!!!!\n");
    }
}

// xoa 1 sinh vien
void deleteStudent(Student *infor,int *number){
    int flap=0;
    char ma[8];
    fflush(stdin);
    printf("Moi nhap vao ma so lop de xoa : ");
    fgets(ma,sizeof(ma),stdin);
    ma[strcspn(ma,"\n")]='\0';
    for (int i = 0; i < *number; i++) {
        if (strcmp(infor[i].id, ma) == 0) {
            for (int j = i; j < *number - 1; j++) {
                *(infor + j) = *(infor + j + 1);
            }
            --(*number);
            flap=1;
            printf("Xoa THANH CONG!!!!!\n");
        }
    }
    if(!flap){
        printf("Ma so sinh vien khong ton tai khong ton tai!!!\n");
    }
}

// lua chon tinh nang trong menu quan ly sinh vien
void choiceMenuStudent(){
    while (1) {
        showMenuStudent();
        int choice;
        printf("Moi nhap vao su lua chon cua ban : ");
        scanf("%d", &choice);
        switch (choice) {
            //hien thi thong tin cua cac hoc sinh
            case 1: {
                if(numStudent==0){
                    printf("Chua co sinh vien nao!!!!\n");
                    break;
                }
                else{
                    showInforStudent(stu,numStudent);
                }
                break;
            }
            // them moi 1 sinh vien
            case 2: {
                if(numStudent==MAX) {
                    printf("Mang da day khong the them!!!!!\n");
                    break;
                }
                inputInfoStudent(stu,&numStudent,0);
                break;
            }
            //chinh sua thong tin cua 1 lop hoc
            case 3: {
                editInforStudent(stu,numStudent);
                break;
            }
            // xem thong tin chi tiet cua mot sinh vien
            case 4:{
                showDetailsInforStudent(stu,numStudent);
                break;
            }
            // xoa 1 sinh vien
            case 5:{
                deleteStudent(stu,&numStudent);
                break;
            }
            case 0: {
                break;
            }
            default:
                printf("Lua chon cua ban khong co trong menu!!!!\n");
                break;
        }
        if (choice == 0) {
            printf("Tro lai menu!!!\n");
            break;
        }
    }
}
#endif //UNTITLED4_FUNCTION_H
