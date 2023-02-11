# Healthify_Base
 Approach
We need to make sure that a person is intaking meals per day and is well balanced in calorie to protein intake.We find out the best-balanced diet for a customer, concerning
our problem statement.
The customer chooses, what type of lifestyle he/she is following i.e, Active or Sedentary.
Then we make them punch in their height and weight to calculate their BMI.
We compare the BMI with the data to check if he/she is overweight, under-weight, or optimal weight.
Then we ask them how to move on with their diet, i.e, muscle gain, fat loss, etc.
Depending on the above choice and his lifestyle we define his/her PPG(Protein Per Kilogram)
Like this using ppg and weight, we calculate protein intake per day.
We already have fixed his calorie intake which is 2000 cal(which can be set accordingly), and find out the best food item list he/she should consume in a day to maintain his protein 
and calorie intake for bodybuilding, bulking, cutting, etc.

So, we need to maximize the person’s protein intake keeping calorie intake constant or less.
Hence maximization problem comes under the optimization problem .Here we make use of Dynamic Programming.More specifically Knapsack 1\0 Dynamic Programming, where 
we maximize protein(profit) while keeping calorie(knapsack capacity) less or equal.
We already have the list of food items with their calorie and protein content %. (Items of knapsack)
We adopt the Bottom-up approach or tabulation method for the same as it is less complex and easy to implement.

We store the food ITEMs characteristics 
 Name → string Array items[ ]
 Calorie→ integer array calorie[ ]
 Protein → integer array Protein_content[ ]
We make use of the function make_list() to find out the calorie, and 
protein intake along with the food items he/she would consume in a 
day accordingly to maintain protein and calorie intake per day.


 Data Structures and Algorithms Used
1. Data Structure
  We store the food ITEMs characteristics :
  Name → string Array items[ ]
  Calorie→ integer array calorie[ ]
  Protein → integer array Protein_content[ ]
  DP Table to find max protein content and list of food items→2D integer array K[ ].
  Retrieval of the food item list→ integer array sols[ ]
2. Algorithm
  Knapsack 0/1 Dynamic Programming.
  DP Bottom-Up or tabulation method.
 
 Q. Why are we implementing Dynamic Programming here?

 Sol. Our Problem is a maximization problem i.e, an optimization
problem, and we know Dynamic Programming is used to solve
optimization problems as it always gives a solution, if it exists.
And our problem satisfies two conditions that are needed for a problem 
to be able to solve via DP
 Optimal substructure 
 Overlapping subproblem
