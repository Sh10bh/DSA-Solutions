struct PC { long long c2=0,c3=0,c5=0,c7=0; };

PC digitPC(int d){
    switch(d){
        case 2: return {1,0,0,0};
        case 3: return {0,1,0,0};
        case 4: return {2,0,0,0};
        case 5: return {0,0,1,0};
        case 6: return {1,1,0,0};
        case 7: return {0,0,0,1};
        case 8: return {3,0,0,0};
        case 9: return {0,2,0,0};
        default: return {0,0,0,0};
    }
}

PC subtractPC(PC a, PC b){
    PC r;
    r.c2 = max(0LL, a.c2-b.c2);
    r.c3 = max(0LL, a.c3-b.c3);
    r.c5 = max(0LL, a.c5-b.c5);
    r.c7 = max(0LL, a.c7-b.c7);
    return r;
}

bool isSubset(PC a, PC b){
    return a.c2<=b.c2 && a.c3<=b.c3 && a.c5<=b.c5 && a.c7<=b.c7;
}

array<long long,10> getFactorCount(PC count){
    long long count8 = count.c2/3, remaining2 = count.c2%3;
    long long count9 = count.c3/2, count3 = count.c3%2;
    long long count4 = remaining2/2, count2 = remaining2%2;
    long long count6 = 0;
    if(count2==1 && count3==1){count2=0;count3=0;count6=1;}
    if(count3==1 && count4==1){count2=1;count6=1;count3=0;count4=0;}
    array<long long,10> res{};
    res[2]=count2; res[3]=count3; res[4]=count4; res[5]=count.c5;
    res[6]=count6; res[7]=count.c7; res[8]=count8; res[9]=count9;
    return res;
}

long long sumValues(const array<long long,10>& f){
    long long s=0;
    for(int d=2; d<10; d++) s+=f[d];
    return s;
}

string construct(const array<long long,10>& f){
    string res;
    for(int d=2; d<10; d++) res += string(f[d], char('0'+d));
    return res;
}

pair<PC,bool> getPrimeCount(long long t){
    PC count;
    int primes[4] = {2,3,5,7};
    for(int p : primes){
        while(t % p == 0){
            t /= p;
            if(p==2) count.c2++;
            else if(p==3) count.c3++;
            else if(p==5) count.c5++;
            else count.c7++;
        }
    }
    return {count, t==1};
}

PC getPrimeCountFromString(const string& num){
    PC count;
    for(char ch : num){
        PC d = digitPC(ch-'0');
        count.c2+=d.c2; count.c3+=d.c3; count.c5+=d.c5; count.c7+=d.c7;
    }
    return count;
}

class Solution {
public:
    string smallestNumber(string num, long long t) {
        auto [primeCount, ok] = getPrimeCount(t);
        if(!ok) return "-1";

        auto factorCount = getFactorCount(primeCount);
        long long fcSum = sumValues(factorCount);
        if(fcSum > (long long)num.size()) return construct(factorCount);

        PC primeCountPrefix = getPrimeCountFromString(num);
        size_t zpos = num.find('0');
        int firstZeroIndex = (zpos == string::npos) ? (int)num.size() : (int)zpos;
        if(zpos == string::npos){
            if(isSubset(primeCount, primeCountPrefix)) return num;
        }

        for(int i=(int)num.size()-1; i>=0; i--){
            int d = num[i]-'0';
            primeCountPrefix = subtractPC(primeCountPrefix, digitPC(d));
            int spaceAfter = (int)num.size()-1-i;
            if(i > firstZeroIndex) continue;
            for(int biggerDigit=d+1; biggerDigit<10; biggerDigit++){
                PC need = subtractPC(subtractPC(primeCount, primeCountPrefix), digitPC(biggerDigit));
                auto factorsAfterReplacement = getFactorCount(need);
                long long s = sumValues(factorsAfterReplacement);
                if(s <= spaceAfter){
                    long long fillOnes = spaceAfter - s;
                    return num.substr(0,i) + char('0'+biggerDigit) + string(fillOnes,'1') + construct(factorsAfterReplacement);
                }
            }
        }

        auto factorsAfterExtension = getFactorCount(primeCount);
        long long feSum = sumValues(factorsAfterExtension);
        long long ones = (long long)num.size()+1-feSum;
        return string(ones,'1') + construct(factorsAfterExtension);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna