# Dsa_Assigments
**Data Structures and Algorithms** Assigments for [**Department of Informatics and Telecomunications**](http://dit.uoi.gr/)

[*Univeristy of Ioannina*](http://uoi.gr/)



# [Assigment 1](https://github.com/Pkoutsokeras/Dsa_Assigments/tree/master/Ergasia_1)


* [ask1.cpp](https://github.com/Pkoutsokeras/Dsa_Assigments/blob/master/Ergasia_1/ask1.cpp)

Writes a program that fills an array in size of 100 elements with random integers **between** 0 and 1,000.

Make a function that inserts as parameter the array and returns the **minimum**,**maximum** and **average** of the array.

* [ask2.cpp](https://github.com/Pkoutsokeras/Dsa_Assigments/blob/master/Ergasia_1/ask2.cpp)
 
 Write a programm that reads a **CSV** file named  [«Population figures by Country»](https://datahub.io/JohnSnowLabs/population-figures-by-country)
 
 with elements of population between 1960-2016 and inserts in proper arrays. Then, for each country prints the name and the year that had the biggest change of population.
 
 
 ---
 
 # [Assigment 2](https://github.com/Pkoutsokeras/Dsa_Assigments/tree/master/Ergasia_2)
  
* [ask1.cpp](https://github.com/Pkoutsokeras/Dsa_Assigments/blob/master/Ergasia_2/ask1.cpp)

Write a programm that reads **ALL** the words of a text and prints how many times the every word exists in *ascending order*.
Use as input the Book [1984](http://gutenberg.net.au/ebooks01/0100021.txt) Written by *George Orwell*.
First of all, we need to convert from **lowercase** to **uppercase**.

* [ask2.cpp](https://github.com/Pkoutsokeras/Dsa_Assigments/blob/master/Ergasia_2/ask2.cpp)

  Create a double linked list that supports : 
  * Insert element at front
  * Insert element at back
  * erase element  based on ID
  * Print list from the start to end
  * Print list **Reverse**
  
  1. Read the data from the file [students.txt](https://github.com/Pkoutsokeras/Dsa_Assigments/blob/master/Ergasia_2/students.txt) 
  and isnsert to double linked list. Then print the list from *start* to *end*
  2. Insert in the start of the list the "011 iasonas 3 CS 7.0" and in the end of the list insert the element "012 electra 5 CE 6.0"
  3. Delete the element with **ID** 005. Then prints the list from start to end.
  4. Keep the List **ONLY** with Students that are from CS Class and Grade >5. Print the list reverse.
  
  **Repeat the steps using the double linked list that contains STL**
  
  # [Assigment 3](https://github.com/Pkoutsokeras/Dsa_Assigments/tree/master/Ergasia_3)
  
  * [ask1.cpp](https://github.com/Pkoutsokeras/Dsa_Assigments/blob/master/Ergasia_3/ask1.cpp)
  
  Write a programm that creates a simple [blockchain](https://en.wikipedia.org/wiki/Blockchain).
  
  1. Every block of blockchain will be a struct that contains : **(size_t id,string data,size_t nounce,size_t previous_hash)**
  2.  Write a Function ```size_t hash_combined(block &a_block)``` that returns the hash of a block as verbal that came from the combine of the block elemets.
    For this hash calculation we need to use the ```std:: hash ```
  3. Write a function ```void find_nonce(Block &a_block, int difficulty)``` that changes the value of the field nonce for a_block (*starts from 0 and tesdting consecutively the values that increase by 1*)
  4. The first block must have this values : ```{0, <Current Hour and date>, “GENESIS BLOCK”, <nonce>,0}``` and the date and hour should be hate this format : **YYYY-MM-DD HH:MM:SS.**.
  The nonce will have difficulty value 7. ```difficulty=7```.
  5. Fill 7 blocks so that blockchain that created with difficulty 7 will be like **THIS** : 
  
| id: 0                     | id: 1                            | id: 2                          | id: 3                             |
|---------------------------|----------------------------------|--------------------------------|-----------------------------------|
| ts: 2019-12-01 12:37:15   | ts: 2019-12-01 12:37:24          | ts: 2019-12-01 12:37:55        | ts: 2019-12-01 12:38:02           |
| data: GENESIS block       | data: Alice pays 10 euros to Bob | data: Bob pays 5 euros to Carl | data: Carl pays 10 euros to David |
| nonce: 7705472            | nonce: 20662197                  | nonce: 4180543                 | nonce: 3124703                    |
| p_hash: 0                 | p_hash: 7409222825570000000      | p_hash: 14415237325170000000   | p_hash: 9785420976540000000       |
| hash: 7409222825570000000 | hash: 14415237325170000000       | hash: 9785420976540000000      | hash:15500881473790000000         |  

| id: 4                             | id: 5                           | id: 6                           | id: 7                     |
|-----------------------------------|---------------------------------|---------------------------------|---------------------------|
| ts:2019-12-01 12:38:07            | ts: 2019-12-01 12:38:24         | ts: 2019-12-01 12:39:08         | ts: 2019-12-01 12:39:17   |
| data: David pays 2 euros to Alice | data: Alice pays 2 euros to Bob | data: Bob pays 5 euros to David | data: Carl pays 5 euros to Alice |
| nonce: 11311765                   | nonce: 28602793                 | nonce: 5567229                  | nonce: 6164283            |
| p_hash: 15500881473790000000      | p_hash: 17403203628000000000    | p_hash: 847005160950000000      | p_hash: 10509950750660000000     |
| hash:17403203628000000000         | hash:847005160950000000         | hash:10509950750660000000       | hash:11846123523500000000        |           

 vi. Write a `bool check_valid_blockchain(list <block> &chain)` that returns if the blockchain is valid or not,testing the recorded value of previous_hash in every block with the hash value of the previous block.check the valid of the blockchain.

 vii. change the next-to-last block with the data `Bob pays 5000 euros to David` and check the valid of blockchain again.

   * [ask2.cpp](https://github.com/Pkoutsokeras/Dsa_Assigments/blob/master/Ergasia_3/ask2.cpp)  
  Write the [algorithm of Kahn](https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/) for the topological sort Directed Acyclic Graphs. The graphs are recorded in adjacency arrays. Here is an **Example** *:*

      ![alt text](https://i.ibb.co/8Pv0MyT/Screenshot-from-2020-01-06-00-48-20.png)

1. Read the [file](https://github.com/Pkoutsokeras/Dsa_Assigments/blob/master/Ergasia_3/dag1.txt) that stores a DAG.
2. Develop the Algorithm topological sort of Kahn and Record the [*Results*](https://github.com/Pkoutsokeras/Dsa_Assigments/blob/master/Ergasia_3/results.txt) in a text file.
 
