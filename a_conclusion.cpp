//
// Created by xuhang on 2021/5/8.
//

/* OJi输入篇
 * 1.告诉行数，输入N行 pta1018(不建议这样用)
 * cin << N;
 * for
 * cin << a << b
 *
 * 2.告诉N 以及后续N行，建议把while(cin>>N)作为条件，判断cin的状态
 * int N;
 * while(cin >> N){
 * for int
 * cin >> }
 *
 * 3.直接输入一组数，不告诉你长度
 * while(cin >> a >> b){
 * 流处理，比较常规}
 *
 * 4.给定字符或字符串处理
 *     字符 char ch;
 *     1.cin >> ch; 字符处理
 *     2.while(cin.get(ch)) 字符处理
 *     字符串string input;
 *     1.getline(cin,input);
 *     2.cin>>input
 *     3.while(1./2.) 推荐！
 *
 * 5.给定N，输入N个字符串
 * int N
 * string temp;
 * while(cin<<N){
 * vector<string> input;
 * for N
 *    cin>>temp
 *    input.push_back(temp); //vector向量的保存
 * }
 *
 * 6.未知字符串
 * vector<string> input;
 * string temp;
 * while(cin >> temp)
 * {
 * input.push_back(temp);
 * }
 *
 *
 * 7.不告诉你几组几行结束，告诉你每组一个数字是N，后面跟着N个数字
 * ==>不告诉你几行结束的肯定要用while(cin >> N)
 *  4 1 2 3 4
 *  5 1 2 4 5 6
 *  ...
 *
 *  int N;
 *  while(cin >> N){
 *  while(N-->0){
 *  int a;
 *  cin >> a;
 *  }
 *  }
 */


/*2.输出篇
 * 输出没有必要全部用cout<<
 * 可以使用 printf("%04d - %04d")  这样输出格式比cout方便很多 (pta1019）
 */