    static String decrypt(String encrypted_message) {
        int keys[] = {8,2,5,1,2,2,0};
        StringBuilder final_string = new StringBuilder();
        int i = 0;
        for (char ch: encrypted_message.toCharArray()) {
            if (i == keys.length) {
                i = 0;
            }
            if (Character.isLetter(ch)) {
                char first = ch <= 'Z' ? 'A' : 'a';
                ch = (char)(ch - keys[i]);
                if (ch < first){
                    ch = (char)(ch + 26);
                }
                i += 1;
            }
            final_string.append(ch);
        }
        return final_string.toString();
    }



hacking time
https://www.careercup.com/question?id=5633094794084352
