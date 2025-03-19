class MyQueue {
    private:
        stack<int> input, output;
    
    public:
        MyQueue() {}
    
        void push(int x) {
            input.push(x);
        }
    
        int pop() {
            if (output.empty()) {
                while (!input.empty()) {
                    output.push(input.top());
                    input.pop();
                }
            }
            int topElement = output.top();
            output.pop();
            return topElement;
        }
    
        int peek() {
            if (output.empty()) {
                while (!input.empty()) {
                    output.push(input.top());
                    input.pop();
                }
            }
            return output.top();
        }
    
        bool empty() {
            return input.empty() && output.empty();
        }
    };
    