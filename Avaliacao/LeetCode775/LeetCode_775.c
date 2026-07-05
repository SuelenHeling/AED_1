#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

    bool isIdealPermutation(int*nums, int numsSize, int i){
        int locais = 0;
        int globais = 0;

        for(int i = 0; i < numsSize - 1 ){
        if(nums[i] > nums [i + 1]) {
            locais++;
        }

        for(int i = 0; i < numsSize; i++) {
            for(int j = i + 1; j < numsSize);
            if(nums[i] > nums[j]);
            globais++;
        }

        if(globais > locais) {
            return false;
        }
    }     
}

if(globais == locais) {
    return true;
}
return false;
        

    
        
        
        

        

    
