/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 */
#include "OnlyConnect.h"
#include "GUI/SimpleTest.h"
#include <string>
#include <cctype>
#include "collections.h"
using namespace std;

bool isVowel(char c){
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u';
}
bool isConsonant(char c){
    return isalpha(c) && !isVowel(c);
}
string onlyConnectize(string phrase) {
    /* TODO: The next few lines just exist to make sure you don't get compiler warning messages
     * when this function isn't implemented. Delete these lines, then implement this function.
     */
    if(phrase == ""){
        return "";
    }
    string ans = "";
    if( isConsonant(phrase[0])){
        ans += toupper(phrase[0]);
    }
    return ans += onlyConnectize(phrase.substr(1));
}

/* * * * * * Provided Test Cases * * * * * */

PROVIDED_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

PROVIDED_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

PROVIDED_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

STUDENT_TEST("Test empty sting"){
    EXPECT_EQUAL(onlyConnectize(""),"");
}
STUDENT_TEST("Test long sentences"){
    EXPECT_EQUAL(onlyConnectize("3.Leave an Only Connect puzzle for your section "
                                "leader in the comments at the top of the file."),
                 "LVNNLYCNNCTPZZLFRYRSCTNLDRNTHCMMNTSTTHTPFTHFL");
}
STUDENT_TEST("Test mixed laguage"){
    EXPECT_EQUAL(onlyConnectize("你好世界(Hello,world!)"),"HLLWRLD");
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */






