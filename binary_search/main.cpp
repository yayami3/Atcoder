bool isOK(vector<ll> a ,ll index, ll key){
  if(a[index]>=key) return true;
  else return false;
}

ll binary_search(vector<ll> &a, ll key){
  ll left = -1;
  ll right = a.size();
  
  while (right - left > 1) {
    ll mid = left + (right - left) / 2;
    
    if (isOK(mid, key)) right = mid;
    else left = mid;
  }

  return right;
}

int main() {
    cout << binary_search(51) << endl; //
    cout << binary_search(1) << endl; // 
    cout << binary_search(910) << endl; //

    cout << binary_search(52) << endl; // 6
    cout << binary_search(0) << endl; // 0
    cout << binary_search(911) << endl; // 10
}
