# [Flattening a Linked List](https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1)
## Medium
In a linked list, every node has two pointers: next and bottom. The heads of n linked lists are connected using the next pointer, while the bottom pointer points to the next node in the current linked list.
Each linked list is sorted in non-decreasing order of data, and the head nodes are also sorted in non-decreasing order.
Given the head of the first linked list, flatten the linked lists into a single sorted linked list such that every node is connected using only the bottom pointers.
Examples:
Input:Output: 5 -&gt; 7 -&gt; 8 -&gt; 10 -&gt; 19 -&gt; 20 -&gt; 22 -&gt; 28 -&gt; 40 -&gt; 45.Explanation: Bottom pointer of 5 is pointing to 7.Bottom pointer of 7 is pointing to 8.Bottom pointer of 10 is pointing to 20 and so on.
So, after flattening the linked list the sorted list will be 5 -&gt; 7 -&gt; 8 -&gt; 10 -&gt; 19 -&gt; 20 -&gt; 22 -&gt; 28 -&gt; 40 -&gt; 45.
Input:Output: 5 -&gt; 7 -&gt; 8 -&gt; 10 -&gt; 19 -&gt; 22 -&gt; 28 -&gt; 30 -&gt; 50Explanation:Bottom pointer of 5 is pointing to 7.Bottom pointer of 7 is pointing to 8.Bottom pointer of 8 is pointing to 30 and so on.So, after flattening the linked list the sorted list will be 
5 -&gt; 7 -&gt; 8 -&gt; 10 -&gt; 19 -&gt; 22 -&gt; 28 -&gt; 30 -&gt; 50.
Constraints:0&nbsp;≤&nbsp;n ≤ 1041&nbsp;≤&nbsp;number of nodes in each list ≤&nbsp;501&nbsp;≤&nbsp;node-&gt;data ≤ 5*105