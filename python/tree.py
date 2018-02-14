from sklearn.tree import DecisionTreeRegressor

class TreeNode:
    def __init__(self, contents, children = None):
        self.children = children
        self.contents = contents

class Tree(DecisionTreeRegressor):
    def __init__(self):
        DecisionTreeRegressor.__init__(self,
            max_depth=20,
            min_samples_split=40,
            min_impurity_decrease=0.01,
            min_impurity_split=0.5)

class Forest:
    def __init__(self):
        self.trees = []

    def add_tree(self, tree):
        self.trees.append(tree)

    def predict(self, features):
        for t in self.trees:
            t.predict
