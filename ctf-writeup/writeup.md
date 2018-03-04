# stego
## Pictorial mess

> Johnny had an image that he was going to use for a very important purpose. Someone had hacked into his system and tampered with the image. Help him recover it.

1. 先用Stegsolve.jar对图片进行分析，会在图片中得到**makeittall**。在尝试了各种形式的这句话之后提交无效，说明还有后续步骤。
2. 根据意思，应该是把图片变高，所以修改二进制，是图片恢复为400*400，发现下面有黑白交替的小方格。
3. 假设黑色=1，白色=0，可以得到，7组长度为20的数字，将其写成7*20的形式，得到
> 1110000
1100011
1110100
1100110
1111011
1000010
0110011
1111001
1101111
1101110
1100100
1110100
1101000
0110011
1110011
0110001
1100111
1101000
1110100
1111101
4. 转成ascii就是pctf{B3yondth3s1ght}


# web
## Unfinished business
> There was a miscellaneous platform being built for various purposes, but it had to be shelved halfway through.
Wanna check it out? Here is the link: http://128.199.224.175:25000/
Note: Use your Pragyan CTF credentials to log in.

1. 勾上admin选项登录网页时会发现，网页到了admin.php，紧接着会重定向到unavailable.php
2. 用wireshark抓包，可以抓到flag



---
# 一点思路
## Ears to the rescue
- 用matlab分析音频可以得到其频率的具体值为（正负）0.976562500000000，0.732421875000000，0.494384765625000，0.247192382812500
- 这几个数都可以做质因数分解
## INTO THE NEXT DIMENSION
- 将文件后缀改成.fbx
- 能查看到里面有几个object
## Xmen OR the avengers 
- 做异或得到"i am a hydra agenT, coverly spying on the superHeroes. I am aware of the group that iS going to aTtack you...but Hydra has had its diffErences with you in the past, so i'm not going to maKe it vEry simple for You ....ecb...aes(I Vouch for this: 12345)...md5(this)...base64..."
- 应该用上ecb，ACE（IV是12345？？？），md5加密密码，密码是 "i am a hydra agenT, coverly spying on the superHeroes. I am aware of the group that iS going to aTtack you...but Hydra has had its diffErences with you in the past, so i'm not going to maKe it vEry simple for You ."
- 应该是组合这几种方式

