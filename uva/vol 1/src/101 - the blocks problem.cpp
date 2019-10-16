//  101 - Blocks Problem Solution
//
//  Created by Ridhwanul Haque  on 2/8/18.
//  Copyright © 2018 rhemon. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Block {
    int position;
    int block_id;
public:
    Block(int id, int n);
    void set_pos(int n);
    int get_pos();
    int get_id();
};
Block::Block(int id, int n) {
    position = n;
    block_id = id;
}
void Block::set_pos(int n) {
    position = n;
}
int Block::get_pos() {
    return position;
}
int Block::get_id() {
    return block_id;
}

class Stack {
    vector<Block> blocks;
    vector<vector<Block>> stacks;
    int get_stack_pos(int block_number);
public:
    Stack(int n);
    void move_onto(int a, int b);
    void move_over(int a, int b);
    void pile_over(int a, int b);
    void pile_onto(int a, int b);
    int in_stack(int a, int b);
    vector<Block> get(int n);
};

Stack::Stack(int n) {
    vector<Block> temp_blocks;
    vector<vector<Block>> temp_stacks;
    for (int i = 0; i < n; i++){
        Block block(i, i);
        temp_blocks.push_back(block);
        vector<Block> temp_stack;
        temp_stack.push_back(block);
        temp_stacks.push_back(temp_stack);
    }
    blocks = temp_blocks;
    stacks = temp_stacks;
}

void Stack::move_onto(int a, int b) {
    // where is a and b
    int a_pos = blocks[a].get_pos();
    int b_pos = blocks[b].get_pos();

    // collect stacks in those positions
    vector<Block> stack_with_a = stacks[a_pos];
    vector<Block> stack_with_b = stacks[b_pos];

    // fill up those pos with empty vector temporarily
    vector<Block> temp;
    stacks.at(a_pos) = temp;
    stacks.at(b_pos) = temp;

    // on stack with a find where a is, and remove any on top
    bool found_a = false;
    int row;
    vector<Block> replacement_1;
    for (row = 0; row < stack_with_a.size() && !found_a; row++) {
        if (stack_with_a[row].get_id() == a) {
            found_a = true;
            for(int row2 = row+1; row2 < stack_with_a.size(); row2++){
                Block block = stack_with_a.at(row2);
                block.set_pos(block.get_id());
                blocks.at(block.get_id()) = block;
                vector<Block> temp_stack;
                temp_stack.push_back(block);
                stacks.at(block.get_id()) = temp_stack;
            }
        } else {
            replacement_1.push_back(stack_with_a[row]);
        }
    }
    stacks.at(a_pos) = replacement_1;

    // do same for the ones b
    vector<Block> replacement_2;
    bool found_b = false;
    for (row = 0; row < stack_with_b.size() && !found_b; row++) {
        if (stack_with_b[row].get_id() == b) {
            found_b = true;
            replacement_2.push_back(stack_with_b[row]);
            for (int row2 = row+1; row2 < stack_with_b.size(); row2++) {
                Block block = stack_with_b.at(row2);
                block.set_pos(block.get_id());
                blocks.at(block.get_id()) = block;
                vector<Block> temp_stack;
                temp_stack.push_back(block);
                stacks.at(block.get_id()) = temp_stack;
            }
        } else {
            replacement_2.push_back(stack_with_b[row]);
        }
    }

    // add a to the replacement_2 of b
    Block block = blocks[a];
    block.set_pos(b_pos);
    blocks.at(a) = block;
    replacement_2.push_back(block);
    stacks.at(b_pos) = replacement_2;
}

void Stack::move_over(int a, int b) {
    // where is a and b
    int a_pos = blocks[a].get_pos();
    int b_pos = blocks[b].get_pos();

    // collect stacks in those positions
    vector<Block> stack_with_a = stacks[a_pos];
    vector<Block> stack_with_b = stacks[b_pos];

    // fill up those pos with empty vector temporarily
    vector<Block> temp;
    stacks.at(a_pos) = temp;
    stacks.at(b_pos) = temp;

    // on stack with a find where a is, and remove any on top
    bool found_a = false;
    int row;
    vector<Block> replacement_1;
    for (row = 0; row < stack_with_a.size() && !found_a; row++) {
        if (stack_with_a[row].get_id() == a) {
            found_a = true;
            for(int row2 = row+1; row2 < stack_with_a.size(); row2++){
                Block block = stack_with_a.at(row2);
                block.set_pos(block.get_id());
                blocks.at(block.get_id()) = block;
                vector<Block> temp_stack;
                temp_stack.push_back(block);
                stacks.at(block.get_id()) = temp_stack;
            }
        } else {
            replacement_1.push_back(stack_with_a[row]);
        }
    }
    stacks.at(a_pos) = replacement_1;

    // add a to the stack_with_b
    Block block = blocks[a];
    block.set_pos(b_pos);
    blocks.at(a) = block;
    stack_with_b.push_back(block);
    stacks.at(b_pos) = stack_with_b;
}

void Stack::pile_onto(int a, int b) {
    // where is a and b
    int a_pos = blocks[a].get_pos();
    int b_pos = blocks[b].get_pos();

    // collect stacks in those positions
    vector<Block> stack_with_a = stacks[a_pos];
    vector<Block> stack_with_b = stacks[b_pos];

    // fill up those pos with empty vector temporarily
    vector<Block> temp;
    stacks.at(a_pos) = temp;
    stacks.at(b_pos) = temp;

    vector<Block> replacement_2;
    bool found_b = false;
    int row;
    for (row = 0; row < stack_with_b.size() && !found_b; row++) {
        if (stack_with_b[row].get_id() == b) {
            found_b = true;
            replacement_2.push_back(stack_with_b[row]);
            for (int row2 = row+1; row2 < stack_with_b.size(); row2++) {
                Block block = stack_with_b.at(row2);
                block.set_pos(block.get_id());
                blocks.at(block.get_id()) = block;
                vector<Block> temp_stack;
                temp_stack.push_back(block);
                stacks.at(block.get_id()) = temp_stack;
            }
        } else {
            replacement_2.push_back(stack_with_b[row]);
        }
    }

    // Add blocks above a to replacement_2, and keep the reset
    vector<Block> replacement_1;
    bool found_a = false;
    for (row = 0; row < stack_with_a.size() && !found_a; row++) {
        if (stack_with_a[row].get_id() == a) {
            found_a = true;
            for (int row2 = row; row2 < stack_with_a.size(); row2++) {
                Block block = stack_with_a[row2];
                block.set_pos(b_pos);
                blocks.at(block.get_id()) = block;
                replacement_2.push_back(block);
            }
        } else {
            replacement_1.push_back(stack_with_a[row]);
        }
    }

    stacks.at(a_pos) = replacement_1;
    stacks.at(b_pos) = replacement_2;
}

void Stack::pile_over(int a, int b) {
    // where is a and b
    int a_pos = blocks[a].get_pos();
    int b_pos = blocks[b].get_pos();

    // collect stacks in those positions
    vector<Block> stack_with_a = stacks[a_pos];
    vector<Block> stack_with_b = stacks[b_pos];

    // fill up those pos with empty vector temporarily
    vector<Block> temp;
    stacks.at(a_pos) = temp;
    stacks.at(b_pos) = temp;

    // Add blocks above a to replacement_2, and keep the reset
    vector<Block> replacement_1;
    bool found_a = false;
    int row;
    for (row = 0; row < stack_with_a.size() && !found_a; row++) {
        if (stack_with_a[row].get_id() == a) {
            found_a = true;
            for (int row2 = row; row2 < stack_with_a.size(); row2++) {
                Block block = stack_with_a[row2];
                block.set_pos(b_pos);
                blocks.at(block.get_id()) = block;
                stack_with_b.push_back(block);
            }
        } else {
            replacement_1.push_back(stack_with_a[row]);
        }
    }

    stacks.at(a_pos) = replacement_1;
    stacks.at(b_pos) = stack_with_b;
}

int Stack::in_stack(int a, int b) {
    // where is a and b
    int a_pos = blocks[a].get_pos();
    int b_pos = blocks[b].get_pos();

    return (a_pos == b_pos);
}

vector<Block> Stack::get(int n) {
    return stacks[n];
}

int main() {
    string block_size_input;
    getline(cin, block_size_input);
    int blocks_number;
    stringstream ss_block_size(block_size_input);
    ss_block_size >> blocks_number;
    Stack blocks(blocks_number);
    string command;
    getline(cin, command);
    while (command != "quit") {
        stringstream sscommand(command);
        string action1, action2;
        int a, b;
        sscommand >> action1 >> a >> action2 >> b;
        if (action1 == "move" && action2 == "over") {
            if (!blocks.in_stack(a, b)) {
                blocks.move_over(a, b);
            }
        } else if (action1 == "move" && action2 == "onto") {
            if (!blocks.in_stack(a, b)) {
                blocks.move_onto(a, b);
            }
        } else if (action1 == "pile" && action2 == "over") {
            if (!blocks.in_stack(a, b)) {
                blocks.pile_over(a, b);
            }
        } else if (action1 == "pile" && action2 == "onto") {
            if (!blocks.in_stack(a, b)) {
                blocks.pile_onto(a, b);
            }
        }
        getline(cin, command);
    }
    for (int i = 0; i < blocks_number; i++){
        vector<Block> block_stack  = blocks.get(i);
        cout << i << ":";
        int j;
        if (block_stack.size() > 0) {
            cout << " ";
            for (j = 0; j < block_stack.size()-1; j++) {
                cout << block_stack[j].get_id() << ' ';
            }
            cout << block_stack[j].get_id();
        }
        cout << '\n';
    }
}
