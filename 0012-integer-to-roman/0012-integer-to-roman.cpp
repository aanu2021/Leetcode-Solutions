class Solution {
public:
    
    
    string intToRoman(int num) {
        
        /*
        
        Original Ones (obeying largest to smallest rule)
        
        1 -> I
        2 -> II
        3 -> III
        5 -> V
        6 -> VI
        7 -> VII
        8 -> VIII
        13 -> XIII
        58 -> LVIII   
            
        
        Exceptional Ones (Don't obey the largest to 
        smallest rules)    
            
        4 -> IV
        9 -> IX
        40 -> XL
        90 -> XC
       400 -> CD
       900 -> CM  
       
       */
        
       
        string res="";
        
        if(num>=1000){
            
            res+="M";
            res+=intToRoman(num-1000);
            return res;
            
        }
        
        if(num>=900){
            
            res+="CM";
            res+=intToRoman(num-900);
            return res;
            
        }
        
        if(num>=500){
            
            res+="D";
            res+=intToRoman(num-500);
            return res;
            
        }
        
        if(num>=400){
            
            res+="CD";
            res+=intToRoman(num-400);
            return res;
            
        }
        
        if(num>=100){
            
            res+="C";
            res+=intToRoman(num-100);
            return res;
            
        }
        
        if(num>=90){
            
            res+="XC";
            res+=intToRoman(num-90);
            return res;
            
        }
        
        if(num>=50){
            
            res+="L";
            res+=intToRoman(num-50);
            return res;
            
        }
        
        if(num>=40){
            
            res+="XL";
            res+=intToRoman(num-40);
            return res;
            
        }
        
        if(num>=10){
            
            res+="X";
            res+=intToRoman(num-10);
            return res;
            
        }
        
        if(num>=9){
            
            res+="IX";
            res+=intToRoman(num-9);
            return res;
            
        }
        
        if(num>=5){
            
            res+="V";
            res+=intToRoman(num-5);
            return res;
            
        }
        
        if(num>=4){
            
            res+="IV";
            res+=intToRoman(num-4);
            return res;
            
        }
        
        if(num>=1){
            
            res+="I";
            res+=intToRoman(num-1);
            return res;
            
        }
        
        return res;
        
    }
};