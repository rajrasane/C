class Node {
    constructor(key) {
        this.key = key;
        this.left = null;
        this.right = null;
    }
}

class BinaryTree {
    constructor() {
        this.root = null;
    }

    insert(key) {
        const newNode = new Node(key);
        if (this.root === null) {
            this.root = newNode;
        } else {
            this.#insertNode(this.root, newNode);
        }
    }

    #insertNode(node, newNode) {
        if (newNode.key < node.key) {
            if (node.left === null) {
                node.left = newNode;
            } else {
                this.#insertNode(node.left, newNode);
            }
        } else {
            if (node.right === null) {
                node.right = newNode;
            } else {
                this.#insertNode(node.right, newNode);
            }
        }
    }

    inorder() {
        const result = [];
        this.#inorderTraversal(this.root, result);
        return result;
    }

    #inorderTraversal(node, result) {
        if (node !== null) {
            this.#inorderTraversal(node.left, result);
            result.push(node.key);
            this.#inorderTraversal(node.right, result);
        }
    }

    preorder() {
        const result = [];
        this.#preorderTraversal(this.root, result);
        return result;
    }

    #preorderTraversal(node, result) {
        if (node !== null) {
            result.push(node.key);
            this.#preorderTraversal(node.left, result);
            this.#preorderTraversal(node.right, result);
        }
    }

    postorder() {
        const result = [];
        this.#postorderTraversal(this.root, result);
        return result;
    }

    #postorderTraversal(node, result) {
        if (node !== null) {
            this.#postorderTraversal(node.left, result);
            this.#postorderTraversal(node.right, result);
            result.push(node.key);
        }
    }

    countNodes() {
        return this.#countNodes(this.root);
    }

    #countNodes(node) {
        if (node === null) {
            return 0;
        }
        return 1 + this.#countNodes(node.left) + this.#countNodes(node.right);
    }

    countLeafNodes() {
        return this.#countLeafNodes(this.root);
    }

    #countLeafNodes(node) {
        if (node === null) {
            return 0;
        }
        if (node.left === null && node.right === null) {
            return 1;
        }
        return this.#countLeafNodes(node.left) + this.#countLeafNodes(node.right);
    }

    search(key) {
        return this.#searchKey(this.root, key);
    }

    #searchKey(node, key) {
        if (node === null) {
            return false;
        }
        if (node.key === key) {
            return true;
        }
        if (key < node.key) {
            return this.#searchKey(node.left, key);
        }
        return this.#searchKey(node.right, key);
    }
}

const tree = new BinaryTree();
const canvas = document.getElementById('treeCanvas');
const ctx = canvas.getContext('2d');

function drawTree(node, x, y, offset) {
    if (node === null) return;

    ctx.fillStyle = 'blue';
    ctx.beginPath();
    ctx.arc(x, y, 20, 0, 2 * Math.PI);
    ctx.fill();

    ctx.fillStyle = 'white';
    ctx.textAlign = 'center';
    ctx.fillText(node.key, x, y + 5);

    if (node.left !== null) {
        ctx.beginPath();
        ctx.moveTo(x, y);
        ctx.lineTo(x - offset, y + 60);
        ctx.stroke();
        drawTree(node.left, x - offset, y + 60, offset / 2);
    }
    if (node.right !== null) {
        ctx.beginPath();
        ctx.moveTo(x, y);
        ctx.lineTo(x + offset, y + 60);
        ctx.stroke();
        drawTree(node.right, x + offset, y + 60, offset / 2);
    }
}

function updateCanvas() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    drawTree(tree.root, canvas.width / 2, 40, 200);
}

function insertKey() {
    const key = parseInt(document.getElementById('keyInput').value);
    tree.insert(key);
    updateCanvas();
    document.getElementById('keyInput').value = '';
}

function inorderTraversal() {
    const result = tree.inorder();
    document.getElementById('output').innerText = `Inorder: ${result.join(', ')}`;
}

function preorderTraversal() {
    const result = tree.preorder();
    document.getElementById('output').innerText = `Preorder: ${result.join(', ')}`;
}

function postorderTraversal() {
    const result = tree.postorder();
    document.getElementById('output').innerText = `Postorder: ${result.join(', ')}`;
}

function countNodes() {
    const result = tree.countNodes();
    document.getElementById('output').innerText = `Total Nodes: ${result}`;
}

function countLeafNodes() {
    const result = tree.countLeafNodes();
    document.getElementById('output').innerText = `Leaf Nodes: ${result}`;
}

function searchKey() {
    const key = parseInt(document.getElementById('keyInput').value);
    const found = tree.search(key);
    document.getElementById('output').innerText = found ? `Key ${key} found` : `Key ${key} not found`;
}
