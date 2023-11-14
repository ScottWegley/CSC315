#include "RationalNumberArray.h"

using namespace std;

RationalNumberArray::RationalNumberArray(int rows, int cols):rows(rows),cols(cols){
    if(rows <= 0 ){
        throw "Cannot create an array with 0 or negative rows";
    }
    if(cols <= 0){
        throw "Cannot create an array with 0 or negative columns";
    }

    
}