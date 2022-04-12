#include <iostream>
#include <fstream>
using namespace std;
string word;
fstream file("file:///home/kemunto/Programming/compiler/parsetree.txt");
void program();
void stmt_sequence();
void statement();
void match(string token);
void if_stmt();
void repeat_stmt();
void assign_stmt();
void read_stmt();
void write_stmt();
void int_stmt();
void exp();
void simple_exp();
void comparison_op();
void term();
void add_op();
void factor();
void error(string location);
int main(int argc, const char * argv[]) {
file >> word;
program();
return 0;
}
void program(){
stmt_sequence();
cout << "Program Succeeded" << endl ;
}
void stmt_sequence(){
statement();
while (word == ";") {
match(";");
statement();
}
cout << "stmt_sequence Succeeded" << endl ;
}
void statement(){
if (word == "if") {
if_stmt();
}else if (word == "repeat"){
repeat_stmt();
}else if (word == "identifier"){
assign_stmt();
}else if (word == "read"){
read_stmt();
}else if (word == "write"){
write_stmt();
}else if (word == "int"){
int_stmt();
}else{
error("statement");
}
cout << "statement Succeeded" << endl ;
}
void if_stmt(){
match("if");
exp();
match("then");
stmt_sequence();
if (word == "else") {
match("else");
stmt_sequence();
}
match("end");
cout << "if statement Succeeded" << endl ;
}
void int_stmt(){
match("int");
cout << "int statement Succeeded" << endl ;
}
void repeat_stmt(){
match("repeat");
stmt_sequence();
match("until");
exp();
cout << "repeat statement Succeeded" << endl ;
}
void assign_stmt(){
match("identifier");
match(":=");
exp();
cout << "assign statement Succeeded" << endl ;
}
void read_stmt(){
match("read");
match("identifier");
cout << "read statement Succeeded" << endl ;
}
void write_stmt(){
match("write");
exp();
cout << "write statement Succeeded" << endl ;}
void exp(){
simple_exp();
if (word == "<" || word == "=") {
comparison_op();
simple_exp();
}
cout << "exp Succeeded" << endl ;
}
void comparison_op(){
if (word == "<") {
match("<");
}else if(word == "="){
match("=");
}else{
error("comparison_op");
}
cout << "comparison op Succeeded" << endl ;
}
void simple_exp(){
term();
while (word == "+" || word == "-") {
if (word == "+") {
match("+");
}else if(word == "-"){
match("-");
}
term();
}
cout << "simple op Succeeded" << endl ;
}
void add_op(){
if (word == "+") {
match("+");
}else if (word == "-"){
match("-");
}else{
error("add_op");
}
cout << "add op Succeeded" << endl ;
}
void term(){
factor();
while (word == "*" || word == "/" ) {
if (word == "*") {
match("*");
}else if(word == "/"){
match("/");
}else{
error("term");
}
factor();
}
cout << "term Succeeded" << endl ;
}
void mul_op(){
if (word == "*") {
match("*");
}else if(word == "/"){
match("/");
}else{
error("mul_op");
}
cout << "mul op Succeeded" << endl ;
}
void factor(){
if (word == "(") {
match("(");
exp();
match(")");
}else if (word == "number"){
match("number");
}else if (word == "identifier"){
match("identifier");
}else{error("factor");
}
cout << "factor Succeeded" << endl ;
}
void match(string token){
if (token == word) {
file >> word;
}else{
error("match");
}
}
void error(string location){
cout << "Problem at " << location << endl ;
exit(0);
}
