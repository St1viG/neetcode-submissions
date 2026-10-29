class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        auto it1 = num1.end() - 1;
        auto it2 = num2.end() - 1;
        vector<int> buffer(num1.size() + num2.size(),0);
        int pos = buffer.size() - 1;
        while(it1 >= num1.begin()){
            int c1 = *it1 - '0';
            auto curr = it2;
            int shift = 0;
            while(curr >= num2.begin()){
                int c2 = *curr - '0';
                c2 *= c1;

                if(c2 > 9) buffer[pos + shift - 1] += c2 / 10;
                buffer[pos + shift] += c2 % 10;

                --curr;
                shift--;
            }
            pos--;
            --it1;
        }
        string sol;
        auto it = buffer.end() - 1;
        while(it >= buffer.begin()){
            if(*it > 9){
                *(it - 1) += *it / 10;
                *it %= 10;
            }
            sol.push_back(*it + '0');
            --it;
        }
        reverse(sol.begin(),sol.end());

        auto itf = sol.begin();
        while(itf != sol.end() && *itf == '0')
            itf++;
        string final(itf, sol.end());
        return final;
    }
};
