# [Subset Sum on Generated Sequence](https://www.geeksforgeeks.org/problems/tricky-subset-problem1557/1?_gl=1*xcsqyk*_up*MQ..*_gs*MQ..&gclid=Cj0KCQjw-frTBhCvARIsADv4XY4WIUNUGgOLZjUt6QtW8gnvnjfXgUSshVjYSrqLMtDYWfWW3XTI5p0aAi6tEALw_wcB&gbraid=0AAAAAC9yBkBdY1-T6kvm_DPZpyCPeGUZt)
## Medium
There are n children standing in a queue, each assigned a number arr[i]. The teacher writes s on a paper and gives it to the first child. 
Each child writes the sum of all numbers already on the paper and arr[i], then passes it to the next child. 
Return true if x can be formed by adding some of the numbers written on the paper: else return false.
Input: arr[] = [1, 2, 4, 2], s = 1, x = 7
Output: true
Explanation: The first student gets 1 on paper and writes 2. The second student gets [1, 2] and writes 5. The third student gets [1, 2, 5] and writes 12. The final sequence of numbers on the paper is 1, 2, 5, 12, 22. Using 2 and 5 we can form 7. 
Input: arr[] = [51, 88], s = 100, x = 500
Output: false
Explanation: The final sequence of numbers on the paper is 100, 151, 339. Using these numbers we cannot form 500. 