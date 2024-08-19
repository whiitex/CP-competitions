class FreqStack {
	set<array<int, 3>, greater<array<int, 3>>> st;
	unordered_map<int, int> mp;
	int counter;

public:
	FreqStack() {
		this->counter = 0;
	}

	void push(int val) {
		++this->counter;
		++this->mp[val];
		this->st.insert({mp[val], this->counter, val});
	}

	int pop() {
		if (this->st.empty()) return 0;

		auto arr = *(this->st.begin());
		int freq = arr[0], count = arr[1];
		this->st.erase(arr);
		--this->mp[arr[2]];

		return arr[2];
	}
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */