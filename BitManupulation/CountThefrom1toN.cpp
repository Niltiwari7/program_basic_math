 typedef long long ll;
    vector<ll> bitCount;

    void getBits(ll number) {
        if (number == 0)
            return;
        
        if (number == 1) {
            bitCount[0]++;
            return;
        }
        
        if (number == 2) {
            bitCount[0]++;
            bitCount[1]++;
            return;
        }

        ll bitLen          = log2(number);
        ll nearestPowerTwo = (1ll << bitLen);
        bitCount[bitLen]  += (number - nearestPowerTwo + 1);

        for (ll i = 0; i < bitLen; i++) {
            bitCount[i] += (nearestPowerTwo / 2);
        }

        number = number - nearestPowerTwo;
        getBits(number);
    }