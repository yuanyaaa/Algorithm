void moveZeroes(vector<int>& nums) {
        int length = nums.size();
        int zeroNum = 0;
        // 相当于双指针，zeroNum相当于查找非零的指针，即左指针，i为右指针 
        // 注释部分为自己写的方法，变量太多了，效率很低
        for(int i = 0; i < length; i++){
            if(nums.at(i) != 0){
                swap(nums.at(zeroNum), nums.at(i));
                zeroNum++;
            }
            // if(nums.at(i) == 0){
            //     zeroNum++;
            // }
            // else{
            //     int index = i;
            //     while(index-1 >= 0 && nums.at(index-1) == 0){
            //         index--;
            //     }
            //     if(index!= i){
            //         nums.at(index) = nums.at(i);
            //         nums.at(i) = 0;
            //     }
                
            // }
        }
        
        // while(zeroNum!= 0){
        //     length--;
        //     nums.at(length) = 0;
        //     zeroNum--;
        // }
    }