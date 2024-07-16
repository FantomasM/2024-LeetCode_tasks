#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

struct ListNode {
         int val;
        ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(const int x) : val(x), next(nullptr) {}
         ListNode(const int x, ListNode *next) : val(x), next(next) {}



     };

class Solution {
public:
    int evaluate_carry(bool & carry) {
        if(carry) {
            return 1;
        }
        else{return 0;}
    }
    void add_two_numbers_two_lists(ListNode * l1, ListNode * l2, ListNode ** result, bool & carry) {

        if(l1->val+l2->val+evaluate_carry(carry)>=10) {
           if(*result==nullptr) {
               *result=new ListNode((l1->val+l2->val+evaluate_carry(carry))%10);
           }
            else {
                (*result)->next=new ListNode((l1->val+l2->val+evaluate_carry(carry))%10);
                *result=(*result)->next;

            }
            carry=true;
        }
        else {
            if(*result==nullptr) {
                *result=new ListNode((l1->val+l2->val+evaluate_carry(carry)));
            }
            else {
                (*result)->next=new ListNode(l1->val+l2->val+evaluate_carry(carry));
                *result=(*result)->next;

            }
            carry=false;
        }
    }
    void add_last_carry(ListNode ** result, bool & carry) {
        if(carry) {
            if(*result==nullptr) {
                *result=new ListNode((evaluate_carry(carry)));
            }
            else {
                (*result)->next=new ListNode(evaluate_carry(carry));
                *result=(*result)->next;

            }
            carry=false;
        }
    }
    void add_two_numbers_one_list(ListNode * l1, ListNode ** result, bool & carry) {
        if(l1->val+evaluate_carry(carry) >=10) {
            if(*result==nullptr) {
                *result=new ListNode((l1->val+evaluate_carry(carry))%10);
            }
            else {
                (*result)->next=new ListNode((l1->val+evaluate_carry(carry))%10);
                *result=(*result)->next;

            }
            carry=true;
        }
        else {
            if(*result==nullptr) {
                *result=new ListNode((l1->val+evaluate_carry(carry)));
            }
            else {
                (*result)->next=new ListNode(l1->val+evaluate_carry(carry));
                *result=(*result)->next;

            }
            carry=false;
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * result=nullptr;
        ListNode * cur_result=nullptr;
        bool carry=false;
        while (l1!=nullptr || l2!=nullptr) {

            if(l1!=nullptr && l2!=nullptr) {
                add_two_numbers_two_lists(l1,l2,&cur_result,carry);
                l1=l1->next;
                l2=l2->next;
            }
            else if(l1!=nullptr && l2==nullptr) {
                add_two_numbers_one_list(l1,&cur_result,carry);
                l1=l1->next;
            }
            else if(l1==nullptr && l2!=nullptr) {
                add_two_numbers_one_list(l2,&cur_result,carry);
                l2=l2->next;
            }
            if(result==nullptr) {
                result=cur_result;
            }
        }
        add_last_carry(&cur_result,carry);
        return result;
    }
};
void delete_List(ListNode * list) {
    if(list==nullptr) {
        return;
    }
    ListNode * tmp=list->next;
    delete list;
    delete_List(tmp);
}
int main(void) {
    ListNode * first_1=new ListNode(2);
    first_1->next=new ListNode(4);
    first_1->next->next=new ListNode(3);

    ListNode * first_2=new ListNode(5);
    first_2->next=new ListNode(6);
    first_2->next->next=new ListNode(4);

    Solution sol;
    ListNode * result=sol.addTwoNumbers(first_1,first_2);
    assert(result!=nullptr && result->val==7 && result->next!=nullptr && result->next->val==0 && result->next->next!=nullptr && result->next->next->val==8 && result->next->next->next==nullptr);
    delete_List(first_1);
    delete_List(first_2);
    delete_List(result);

    ListNode * second_1=new ListNode(0);


    ListNode * second_2=new ListNode(0);



    ListNode * result_2=sol.addTwoNumbers(second_1,second_2);
    assert(result_2!=nullptr && result_2->val==0 && result_2->next==nullptr);
    delete_List(second_1);
    delete_List(second_2);
    delete_List(result_2);


    ListNode * third_1=new ListNode(9);
    third_1->next=new ListNode(9);
    third_1->next->next=new ListNode(9);
    third_1->next->next->next=new ListNode(9);
    third_1->next->next->next->next=new ListNode(9);
    third_1->next->next->next->next->next=new ListNode(9);
    third_1->next->next->next->next->next->next=new ListNode(9);

    ListNode * third_2=new ListNode(9);
    third_2->next=new ListNode(9);
    third_2->next->next=new ListNode(9);
    third_2->next->next->next=new ListNode(9);


    ListNode * result_3=sol.addTwoNumbers(third_1,third_2);
    assert(result_3!=nullptr && result_3->val==8 &&
        result_3->next!=nullptr && result_3->next->val==9
        && result_3->next->next!=nullptr && result_3->next->next->val==9
        && result_3->next->next->next!=nullptr && result_3->next->next->next->val==9 &&
        result_3->next->next->next->next!=nullptr && result_3->next->next->next->next->val==0 &&
        result_3->next->next->next->next->next!=nullptr && result_3->next->next->next->next->next->val==0 &&
        result_3->next->next->next->next->next->next!=nullptr && result_3->next->next->next->next->next->next->val==0 &&
        result_3->next->next->next->next->next->next->next!=nullptr && result_3->next->next->next->next->next->next->next->val==1 &&
        result_3->next->next->next->next->next->next->next->next==nullptr);
    delete_List(third_1);
    delete_List(third_2);
    delete_List(result_3);


}