//
//  Student.hpp
//  Project 3
//
//  Created by Alex Berthon on 9/28/16.
//  Copyright © 2016 Alex Berthon. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include "myDate.hpp"
#include <cstring>

struct Student{
    //the ID number of the student, type int
    int ID;
    
    //the name of the student, type cstring / array of characters
    char name[10];
    
    //the birthday of the student, type myDate
    myDate birthDay;
    
    //the students grade in the class, type int
    int grade;
};

#endif /* Student_hpp */
