# Shipping-Recommender
In this project we are dealing with the real-world scenario of order booking of the electronics items like mobile phones, TVs, Laptops, etc. In this case the if a person has to order an electronic product or has to pre-book a certain product then the shopkeeper has to look into the stocks available for pre-order and the stock of item available with him. Pre-order products are dispatched on the basis of the priority’s assigned by the shopkeeper while the normally available products are dispatched on first come first serve basis. 
Priorities are assigned as follows:


    Card                                               Priority

   Platinum Card                                                  1
   
   Gold Card                                                         2
 
   Silver Card                                                       3

   New Customer                                                 4


On the basis of these priorities the order must be dispatched and in case there is a case where there is the same order of same product by the two customers having same priority cards so, the product will be shipped on the basis of first come first serve basis between the two customers. So, the main purpose of this project is to manage the shipping of the orders placed and setting the priority of the pre-booked orders.







Problem Analysis

In this project we are implementing linked lists, priority queue, file handling of csv files, converting the string into integer data type. Whenever an order is placed the data gets stored into the linked lists after checking the available quantity from the csv file. After the order is placed, in case of pre booking the order is shipped according to priorities on the basis of card allotted to the customer and in case of normal orders, shipping is on fist come first basis.


Methodology Used

Pseudocode for connecting .csv file to c++ 
Declare the ifstream object
Open the desired csv file
Repeat while end of file is reached
Retrieve (pdata,var,',') //separated by comma values

Pseudocode for giving priority to customers

Make a new node of pre-booking type structure
If the pre-booking queue is empty insert the new node at the first position
Else iterate through the list while the priority of the current node is greater than or equal to the priority of the new node
Priority is checked considering the 3rd digit (from right) of the card number of a customer.
If the resultant node is first node then insert the new node at the first position 
Else insert the new node at the position just before the resultant node.

Pseudocode for showing the pre-booking list
Take a pointer pointing to the first node of the pre-booking queue
Iterate through the queue while the pointer doesn’t become NULL
Print all the variables stored in the structure of the pre-booking queue
Go to the next node

Result and Conclusions

Time complexity of the Program 

Time complexity when data is stored in linked lists is Big-O
Time complexity in rest of the program is Big-O(n)

Outputs of the Program

      
Fig. 1 Main Page
            
Fig. 2 Order Request

    
Fig. 3 pre booking list
