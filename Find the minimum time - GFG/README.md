# Find the minimum time
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Geek wants to scan N documents using two scanners. If S1 and S2 are the time taken by the scanner 1 and scanner 2 to scan a single document, find the minimum time required to scan all the N documents. You can use one or more scanners at a time.</span></p>

<p><br>
<strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> 
S1 = 2, S2 = 4, N = 2
<strong>Output:</strong> 4
<strong>Explaination:</strong> Here we have two possibilities. 
Either scan both documents in scanner 1 or
scan one document in each scanner. 
In both the cases time required is 4.</span></pre>

<p>&nbsp;</p>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> 
S1 = 1, S2 = 3, N = 2
<strong>Output:</strong> 2
<strong>Explaination:</strong> Here the optimal approach is to 
scan both of them in the first scanner.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything. Your task is to complete the function <strong>minTime()</strong> which takes S1, S2 and N as input parameters and returns the minimum tme required to scan the documents.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(logN)<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ S1, S2, N ≤ 10<sup>6</sup><br>
1 ≤ S1*N, S2*N ≤ 10<sup>9</sup></span></p>
</div>