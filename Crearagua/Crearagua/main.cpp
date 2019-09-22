//
//  main.cpp
//  Crearagua
//
//  Created by Fabiola on 9/21/19.
//  Copyright © 2019 Fabiola Jimenez. All rights reserved.
#include <iostream>
#include <omp.h>
#include "Molecula.h"
#include "Aleatorizador.h"
#include "barrera.h"

int main(int argc, const char * argv[]) {
    
    
#pragma omp parallel
    
#pragma omp critical
    std::cout << "Greetings from thread "<<omp_get_thread_num()<<std::endl;
    return 0;
}
