/*418. Sentence Screen Fitting
Given a rows x cols screen and a sentence represented as a list of strings, return the number of times the given sentence can be fitted on the screen.
The order of words in the sentence must remain unchanged, and a word cannot be split into two lines. A single space must separate two consecutive words in a line.
Input: sentence = ["hello","world"], rows = 2, cols = 8   Output: 1
Input: sentence = ["a", "bcd", "e"], rows = 3, cols = 6   Output: 2
Input: sentence = ["i","had","apple","pie"], rows = 4, cols = 5   Output: 1     */
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        int words = 0;
        unordered_map<int, int> umap;
        for(int i=0; i<rows; i++){
            // start: Index of the word with which the line starts (init it starts with 0th word)
            int start = words % n;
            if(umap.count(start)){
                words += umap[start];
            }
            else{
                int addedWordCnt=0; 
                // addedWordCnt: number of words that can be added in the line starting with start index
                // len: represents the letters that we are adding in this line and should be <= cols
                // j: helps in iterating over words in the sentence
                // addedWordCnt increased by 1 after every iter since we can fit in 1 word each iteration
                // j=j+1%n since we want to access the 1st letter after n if we can fit it in same line.
                for(int j=start, len=0; len<=cols; j=(j+1)%n , addedWordCnt++){
                    if(len+sentence[j].size() > cols) break;
                    else len += sentence[j].size() + 1;
                        // if the word can be added, add 1 for space as well.this may break the cols and there may not be space for the 'space' 
                        // but the word gets in safely & in that case, we wont add the space, simple!
                }
                words += addedWordCnt;
                umap[start] = addedWordCnt;
            }
        }
        return words/n;
    }
};


