// Works only for small inputs


class Solution {
public:
    int convert_to_int(string in){
        int num = 0, sum=0, mul = 1;
        for(int i=in.size()-1; i>=0;i--){
            num = in[i]-'0';
            sum += (num * mul);
            mul *= 2;
        }
        return sum;
    }

    string convert_to_binary(int sum){
        char c;
        string s;
        int rem=0;
        while(sum != 1){
            rem = sum % 2;
            c = rem + '0';
            s.push_back(c);
            sum = sum/2;
        }
        s.push_back('1');
        return s;
    }

    string addBinary(string a, string b) {
        int sum = 0;
        string out;
        int int_a = convert_to_int(a);
        int int_b = convert_to_int(b);

        sum = int_a + int_b;
        if(sum == 0) return "0";

        out =  convert_to_binary(sum);

        reverse(out.begin(),out.end());

        return out;
    }

};
