/*
International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, "cba" can be written as "-.-..--...", (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

Example:
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation:
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".
*/

class Solution {
public:
    string moorseCode(char c){
        switch(c){
            case 'a':
                return ".-";
                break;
            case 'b':
                return "-...";
                break;
            case 'c':
                return "-.-.";
                break;
            case 'd':
                return "-..";
                break;
            case 'e':
                return ".";
                break;
            case 'f':
                return "..-.";
                break;
            case 'g':
                return "--.";
                break;
            case 'h':
                return "....";
                break;
            case 'i':
                return "..";
                break;
            case 'j':
                return ".---";
                break;
            case 'k':
                return "-.-";
                break;
            case 'l':
                return ".-..";
                break;
            case 'm':
                return "--";
                break;
            case 'n':
                return "-.";
                break;
            case 'o':
                return "---";
                break;
            case 'p':
                return ".--.";
                break;
            case 'q':
                return "--.-";
                break;
            case 'r':
                return ".-.";
                break;
            case 's':
                return "...";
                break;
            case 't':
                return "-";
                break;
            case 'u':
                return "..-";
                break;
            case 'v':
                return "...-";
                break;
            case 'w':
                return ".--";
                break;
            case 'x':
                return "-..-";
                break;
            case 'y':
                return "-.--";
                break;
            case 'z':
                return "--..";
                break;
        }

        return "NULL";
    }

    int uniqueMorseRepresentations(vector<string>& words) {

        if(words.empty()) return 0;

        set<string> output;
        string s;

        for(int i=0; i<words.size();i++){
            s = "";
            for(int j=0; j<words[i].size();j++){
                s += moorseCode(words[i][j]);
            }
            output.insert(s);
        }

        /*sort(output.begin(),output.end());

        for(int i=0; i<output.size()-1; i++){
            if(output[i] == output[i+1]){
                output.erase(output.begin()+i);
                i=-1;
            }
        }*/

        return output.size();
    }
};
