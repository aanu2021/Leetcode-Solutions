# AVL Tree Insertion
## Hard
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a AVL tree and N values to be inserted in the tree. Write a function to insert a given value into the tree.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px">N = 3
Values to be inserted = {5,1,4}</span>

<span style="font-size:18px"><strong>Input:      </strong>
Value to be inserted = 5
<strong>Output:</strong>
    5

</span><span style="font-size:18px"><strong>Input :      </strong>
Value to be inserted = 1
<strong>Output:</strong>
    5
   /
  1

</span><span style="font-size:18px"><strong>Input :      </strong>
Value to be inserted = 4
<strong>Output:</strong>
  5                     4
 /   LR rotation       / \
1   -----------&gt;      1   5
&nbsp;\
&nbsp;4
</span>
</pre>

<p><br>
<span style="font-size:18px"><strong>Your Task: &nbsp;</strong><br>
You dont need to read input or print anything. Complete the function<strong> insertToAVL()</strong> which takes the root of the tree and the value of the node to be inserted as input parameters and returns the root of the modified tree.</span></p>

<p><span style="font-size:18px"><strong>Note:</strong><br>
The tree will be checked after each insertion.&nbsp;<br>
If it violates the properties of balanced BST, an error message will be printed followed by the inorder traversal of the tree at that moment.<br>
If instead all insertions are successful, inorder traversal of tree will be printed.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(log N)<br>
<strong>Expected Auxiliary Space: </strong>O(height of tree)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 500</span></p>
</div>