/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int tar = 0;
    int binSearch1( MountainArray &mountainArr,int &s,int &e){
        while(s<=e){
            int mid = (e-s)/2 + s;
            if(mountainArr.get(mid)==tar){
                return mid;
            }else if(mountainArr.get(mid)<tar){
                s = mid+1;
            }else{
                e = mid-1;
            }
        }
        return -1;
    }
    int binSearch2(MountainArray &mountainArr,int &s,int &e){
            while(s<=e){
            int mid = (e-s)/2 + s;
            if(mountainArr.get(mid)==tar){
                return mid;
            }else if(mountainArr.get(mid)<tar){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        tar = target;
        int s = 0, e=mountainArr.length()-1;

        while(s<e){
            int mid = (e-s)/2 + s;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                s = mid+1;
            }else{
                e = mid;
            }
        }
        int p = s;
        s = 0, e= mountainArr.length()-1;
        int check1 = -1, check2 = -1;
         check1 = binSearch1(mountainArr,s,p);
         p++;
         check2 = binSearch2(mountainArr,p,e);
         if(check1!=-1)return check1;
         if(check2!=-1)return check2;

         return -1;


    }
};