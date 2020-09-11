//
//  main.cpp
//  MMX-SSE
//
//  Created by zhozh on 17.02.2020.
//  Copyright © 2020 zhozh. All rights reserved.
//

#include <stdio.h>
//#include <conio.h>
#include <xmmintrin.h>
#include <mmintrin.h>
#include <immintrin.h>
//#include <dvec.h>

using ::_mm_add_ss;
using namespace std;

int main()
{
    char qw1[8] = {1, 1, 1, 1, 1, 1, 1, 1};
    char qw2[8] = {2, 2, 2, 2, 2, 2, 2, 2};
        
    //int a = 1; int b = 2;
    double qw3[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    double qw4[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    double qw5[8] = {0};
        
    float c[4] = {1, 2, 3, 4};
    float d[4] = {5, 6, 7, 8};
        
    double f[2] = {16, 4};
    
    char a128[16] = {1, 18, 3, 19, 5, 21, 7, 23, 9, 25, 11, 27, 13, 29, 15, 31};
    char b128[16] = {17, 2, 19, 4, 21, 6, 23, 8, 25, 10, 27, 12, 29, 14, 31, 16};
        
    asm
    { //mmx
        movq mm0, qw1
        movq mm1, qw2
        //pcmpeqb mm0, mm1
        //paddusb mm0,mm1 // -- суммирование с беззнаковым насыщением 3 3 3 3 3 3 3 3
        //punpckhwd mm0,mm1 // -- распилил по 2 знака с каждого массива 1 1 2 2 1 1 2 2
        movq qw1, mm0
    }
        
    printf("%s\n", "Summing elements of vectors qw1 + qw2 :");
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", qw1[i]);
    }
        
    printf("\n\n");
        
    asm
    { //sse
        movups xmm0, c
        movups xmm1, d
        addps xmm0, xmm1
        movups c, xmm0
    }
        
    printf("%s\n", "Summing elements of vectors c + d :");
        
    for (int i = 0; i < 4; i++)
    {
        printf("%f ", c[i]);
    }
    
    printf("\n");
    
    asm
    { //sse2
        movups xmm1, f
        sqrtpd xmm0, xmm1
        movups f, xmm0
    }
        
    printf("\n%s %f %s %f\n", "Square root of ", f[0], "is", f[1]);
        
    asm
    {
        movups xmm0, a128
        movups xmm1, b128
        pminub xmm0, xmm1
        movups a128, xmm0
    }
        
    printf("\n%s\n", "Comparing elements :");
        
    for (int i = 0; i < 16; i++)
    {
        printf("( %d , %d) ; ", a128[i], b128[i]);
    }
    
    printf("\n");
    printf("\n%s\n", "Minimum elements :");
        
    for (int i = 0; i < 16; i++)
    {
        printf("%d ", a128[i]);
    }
    
    asm
    {//avx
        vmovapd ymm0, qw4
        vmulpd ymm0, ymm0, qw3
        vmovapd qw5, ymm0
    }
    printf("\n");
    printf("\n%s\n", "parallel multiplying with avx");
    for (int i = 0; i < 16; i++)
    {
        printf("%f ", qw5[i]);
    }
    printf("\n\n");
    
    __m128 vector;
    
    float a = 1;
    
    vector = _mm_set_ss(a);
    
    
    
    return 0;
}

