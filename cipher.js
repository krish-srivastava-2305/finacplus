class CaesarCipher {
    constructor(shift) {
        this.shift = shift % 26;
    }
    encode(text) {
        let i = 0;
        let encodedText = '';
        while(i + 1 < text.length) {
            const char = text[i];
            let count = 1;

            while (i + 1 < text.length && text[i + 1] === char) {
                count++;
                i++;
            }
            if(count > 1) {
                encodedText += char + count;
            } else {
                encodedText += char;
            }
            i++;
        }
        return encodedText;
    }

    encrypt(text) {
        const encryptedArray = text.split('').map((char) => {
            if (char >= 'A' && char <= 'Z') {
                return String.fromCharCode(((char.charCodeAt(0) - 65 + this.shift) % 26) + 65);
            } else {
                return char; 
            }
        })

        const encryptedText = encryptedArray.join('');
        return this.encode(encryptedText);
    }
}

const cipher = new CaesarCipher(3);

console.log(cipher.encrypt("AABCCC")); // Output: "D2EF3"
console.log(cipher.encrypt("HELLO")); // Output: "KHO2"