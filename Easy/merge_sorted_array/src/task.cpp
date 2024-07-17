class Solution {
public:
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         vector<int> result_vector;
        result_vector.resize(m+n);
        size_t first_ptr=0;
        size_t second_ptr=0;
        for(size_t i=0;i<m+n;i++) {
            if(first_ptr<m && second_ptr<n) {
                if(nums1[first_ptr]<=nums2[second_ptr]) {
                    result_vector[i]=nums1[first_ptr];
                    
                     
                    first_ptr++;
                }
                else {
                    result_vector[i]=nums2[second_ptr];
                    second_ptr++;
                }
            }
            else if(first_ptr>=m && second_ptr<n) {
                result_vector[i]=nums2[second_ptr];
                second_ptr++;
            }
            else if(first_ptr<m && second_ptr>=n) {
                

                    
                    result_vector[i]=nums1[first_ptr];
                    
                   
                first_ptr++;
            }
        }
        nums1.clear();
        nums1=result_vector;
    }
};
