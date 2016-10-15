//
//  main.cpp
//  Project 3
//
//  Created by Alex Berthon on 9/28/16.
//  Copyright © 2016 Alex Berthon. All rights reserved.
//
#include <iostream>
#include "Student.hpp"
#include <cstring>
#include <algorithm>

//Function to print the arrays to the console
void print(struct Student *list[]);

//function to initialize the structure
void initialization(struct Student list[]);

//function prints menu options to console
void menu();

//initalize sort function prototypes
void sortID(struct Student *list[]);
void sortName(struct Student *list[]);
void sortAge(struct Student *list[]);
void sortGrade(struct Student *list[]);

int main(int argc, const char * argv[]) {
    srand((unsigned)time(0));
    struct Student list[10];
    initialization(list);
    
    //constructing 4 pointer arrays..
    struct Student *ID[10];
    for(int i = 0; i<10; i++){
        ID[i] = &list[i];
    }
    
    struct Student *name[10];
    for(int i = 0; i<10; i++){
        name[i] = &list[i];
    }
    
    struct Student *age[10];
    for(int i = 0; i<10; i++){
        age[i] = &list[i];
    }
    
    struct Student *grade[10];
    for(int i = 0; i<10; i++){
        grade[i] = &list[i];
    }
    
    struct Student *original[10];
    for(int i = 0; i<10; i++){
        original[i] = &list[i];
    }
    
    int choice;
    bool run = 1;
    while(run){
        menu();
        std::cin>>choice;
        switch(choice){
            case 1:
                print(original);
                break;
            case 2:
                sortID(ID);
                print(ID);
                break;
            case 3:
                sortName(name);
                print(name);
                break;
            case 4:
                sortAge(age);
                print(age);
                break;
            case 5:
                sortGrade(grade);
                print(grade);
                break;
            case 6:
                run = 0;
                break;
        }
    }
    return 0;
}

//provides starting values to the structure
void initialization(struct Student list[]){
    //Names
    strcpy(list[0].name, "Bob");
    strcpy(list[1].name, "Mike");
    strcpy(list[2].name, "Smith");
    strcpy(list[3].name, "Alex");
    strcpy(list[4].name, "Joe");
    strcpy(list[5].name, "Taylor");
    strcpy(list[6].name, "Emily");
    strcpy(list[7].name, "Serah");
    strcpy(list[8].name, "Will");
    strcpy(list[9].name, "Tim");
    
    //Random ID
    for (int i = 0; i<10; i++){
        list[i].ID = (rand()%9000) + 1000;
        for(int j = 0; j<10; j++){
            if(list[i].ID == list[j].ID && i!=j){
                list[i].ID = (rand()%9000) + 1000;
            }
        }
    }
    //Randomized grades
    for (int i = 0; i<10; i++){
        list[i].grade = rand()%51 + 50;
    }
    
    //Randomized Birthday
    for (int i = 0; i<10; i++){
        int month = (rand()%12) +1;
        int year = (rand()%5) +1990;
        int day = (rand()% myDate::daysInMonth(month, year))+1;
        
        myDate birthDay = myDate(month, day, year);
        
        list[i].birthDay = birthDay;
    }
}
//Function formats output
void print(struct Student *list[]){
    printf("%-20s" "%-20s" "%-20s" "%-20s\n", "Student ID", "Name", "Birthday", "Grade");
    char a[20];
    for(int i = 0; i<10; i++){
        list[i]->birthDay.display(a);
        printf("%-20i" "%-20s" "%-20s" "%-20i\n",list[i]->ID, list[i]->name, a, list[i]->grade);
    }
    std::cout<<std::endl;
}

//function sorts an array of pointers based on their ID number, highest to lowest
void sortID(struct Student *list[]){
    struct Student *temp;
    int flag = 1;
    int numLength = 10;
    
    for(int i = 1; (i<=numLength) && flag; i++){
        flag = 0;
        for(int j=0; j<(numLength-1); j++){
            if(list[j+1]->ID>list[j]->ID){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
                flag = 1;
            }
        }
    }
}

//function sorts an array of pointers by name, Alphebetical, A-Z
void sortName(struct Student *list[]){
    struct Student *temp;
    int flag = 1;
    int numLength = 10;
    
    for(int i = 1; (i<=numLength) && flag; i++){
        flag = 0;
        for(int j=0; j<(numLength-1); j++){
            if(list[j+1]->name[0]<list[j]->name[0]){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
                flag = 1;
            }
        }
    }
}

//function sorts an array of pointers by age, Oldest first
void sortAge(struct Student *list[]){
    struct Student *temp;
    int flag = 1;
    int numLength = 10;
    
    for(int i = 1; (i<=numLength) && flag; i++){
        flag = 0;
        for(int j=0; j<(numLength-1); j++){
            if(list[j+1]->birthDay.daysBetween(list[j]->birthDay)>0){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
                flag = 1;
            }
        }
    }
}

//function sorts an array of pointers by grade, highest grade first
void sortGrade(struct Student *list[]){
    struct Student *temp;
    int flag = 1;
    int numLength = 10;
    
    for(int i = 1; (i<=numLength) && flag; i++){
        flag = 0;
        for(int j=0; j<(numLength-1); j++){
            if(list[j+1]->grade>list[j]->grade){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
                flag = 1;
            }
        }
    }
}

//function prints the menu to the console
void menu(){
    std::cout<<"Enter 1 to display original list"<<std::endl;
    std::cout<<"Enter 2 to display list sorted by ID"<<std::endl;
    std::cout<<"Enter 3 to display list sorted by name"<<std::endl;
    std::cout<<"Enter 4 to display list sorted by age"<<std::endl;
    std::cout<<"Enter 5 to display list sorted by grade"<<std::endl;
    std::cout<<"Enter 6 to quit"<<"\n"<<std::endl;
}
