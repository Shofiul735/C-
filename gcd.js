const gcd = (a,b)=>{
    if(!b){
        return a;
    }
    return gcd(b,a%b);
}
console.log(gcd(120,140));
console.log(gcd(10213,312));
console.log(gcd(10,30));