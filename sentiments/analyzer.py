import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        self.positives_set = set()
        file = open(positives, "r")
        for line in file:
            if line.startswith(';') == False:
                self.positives_set.add(line.rstrip("\n"))
        file.close()
        
        self.negatives_set = set()
        file = open(negatives, "r")
        for line in file:
            if line.startswith(';') == False:
                self.negatives_set.add(line.rstrip("\n"))
        file.close()

    def analyze(self, text):
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)
        total = 0
        for word in tokens:
            if word.lower() in self.positives_set:
                total += 1
            elif word.lower() in self.negatives_set:
                total -= 1
            else:
                continue
        
        return total
