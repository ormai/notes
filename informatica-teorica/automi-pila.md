# Automi a pila

Un automa a pila è una sestupla $\langle Q,\Sigma, \Gamma , \gamma , q_0, F \rangle$, dove
- $Q$ è l'insieme degli stati
- $\Sigma$ è l'alfabeto
- $\Gamma$ è l'alfabeto della pila
- $\delta: Q\times (\Sigma\cup\{\varepsilon\})\times(\Gamma\cup\{\varepsilon\})\to (Q\times (\Gamma\cup\{\varepsilon\}))^p$
- $q_0\in Q$ è lo stato iniziale
- $F\subseteq Q$ è l'insieme degli stati di accettazione

---

$$L=\{a^nb^{2n}:n\geq 1, n\ dispari\}$$

<?xml version="1.0" standalone="no"?>
<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN" "https://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">

<svg width="800" height="600" version="1.1" xmlns="http://www.w3.org/2000/svg">
	<ellipse stroke="black" stroke-width="1" fill="none" cx="175.5" cy="296.5" rx="30" ry="30"/>
	<text x="167.5" y="302.5" font-family="Times New Roman" font-size="20">q&#8320;</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="327.5" cy="296.5" rx="30" ry="30"/>
	<text x="319.5" y="302.5" font-family="Times New Roman" font-size="20">q&#8321;</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="463.5" cy="296.5" rx="30" ry="30"/>
	<text x="455.5" y="302.5" font-family="Times New Roman" font-size="20">q&#8322;</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="609.5" cy="296.5" rx="30" ry="30"/>
	<text x="601.5" y="302.5" font-family="Times New Roman" font-size="20">q&#8323;</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="609.5" cy="296.5" rx="24" ry="24"/>
	<polygon stroke="black" stroke-width="1" points="80.5,296.5 145.5,296.5"/>
	<polygon fill="black" stroke-width="1" points="145.5,296.5 137.5,291.5 137.5,301.5"/>
	<polygon stroke="black" stroke-width="1" points="205.5,296.5 297.5,296.5"/>
	<polygon fill="black" stroke-width="1" points="297.5,296.5 289.5,291.5 289.5,301.5"/>
	<text x="222.5" y="317.5" font-family="Times New Roman" font-size="20">&#949;, &#949; &gt; $</text>
	<polygon stroke="black" stroke-width="1" points="493.5,296.5 579.5,296.5"/>
	<polygon fill="black" stroke-width="1" points="579.5,296.5 571.5,291.5 571.5,301.5"/>
	<text x="507.5" y="317.5" font-family="Times New Roman" font-size="20">&#949;, $ &gt; &#949;</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 347.574,274.443 A 79.78,79.78 0 0 1 443.426,274.443"/>
	<polygon fill="black" stroke-width="1" points="443.426,274.443 440.034,265.64 434.027,273.635"/>
	<text x="363.5" y="249.5" font-family="Times New Roman" font-size="20">b, A &gt; &#949;</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 446.302,320.832 A 74.25,74.25 0 0 1 344.698,320.832"/>
	<polygon fill="black" stroke-width="1" points="344.698,320.832 347.111,329.952 353.953,322.659"/>
	<text x="363.5" y="361.5" font-family="Times New Roman" font-size="20">b, A &gt; &#949;</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 465.422,326.213 A 70.69,70.69 0 0 1 325.578,326.213"/>
	<polygon fill="black" stroke-width="1" points="325.578,326.213 321.809,334.862 331.701,333.391"/>
	<text x="356.5" y="407.5" font-family="Times New Roman" font-size="20">a, &#949; &gt; AA</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 328.806,266.764 A 69.035,69.035 0 0 1 462.194,266.764"/>
	<polygon fill="black" stroke-width="1" points="462.194,266.764 464.958,257.744 455.297,260.327"/>
	<text x="356.5" y="206.5" font-family="Times New Roman" font-size="20">a, &#949; &gt; AA</text>
</svg>

$$L=\{a^N c^n d^{2n}b^{N+1}: N,n >0\}$$

<svg width="800" height="600" version="1.1" xmlns="http://www.w3.org/2000/svg">
	<ellipse stroke="black" stroke-width="1" fill="none" cx="157.5" cy="188.5" rx="30" ry="30"/>
	<text x="149.5" y="194.5" font-family="Times New Roman" font-size="20">q&#8320;</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="318.5" cy="188.5" rx="30" ry="30"/>
	<text x="310.5" y="194.5" font-family="Times New Roman" font-size="20">q&#8321;</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="483.5" cy="188.5" rx="30" ry="30"/>
	<text x="475.5" y="194.5" font-family="Times New Roman" font-size="20">q&#8322;</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="640.5" cy="188.5" rx="30" ry="30"/>
	<text x="632.5" y="194.5" font-family="Times New Roman" font-size="20">q&#8323;</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="640.5" cy="344.5" rx="30" ry="30"/>
	<text x="632.5" y="350.5" font-family="Times New Roman" font-size="20">q&#8324;</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="483.5" cy="344.5" rx="30" ry="30"/>
	<text x="475.5" y="350.5" font-family="Times New Roman" font-size="20">q&#8325;</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="318.5" cy="344.5" rx="30" ry="30"/>
	<text x="310.5" y="350.5" font-family="Times New Roman" font-size="20">q&#8326;</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="157.5" cy="344.5" rx="30" ry="30"/>
	<text x="149.5" y="350.5" font-family="Times New Roman" font-size="20">q&#8327;</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="157.5" cy="344.5" rx="24" ry="24"/>
	<polygon stroke="black" stroke-width="1" points="187.5,188.5 288.5,188.5"/>
	<polygon fill="black" stroke-width="1" points="288.5,188.5 280.5,183.5 280.5,193.5"/>
	<text x="208.5" y="209.5" font-family="Times New Roman" font-size="20">&#949;, &#949; &gt; $</text>
	<polygon stroke="black" stroke-width="1" points="348.5,188.5 453.5,188.5"/>
	<polygon fill="black" stroke-width="1" points="453.5,188.5 445.5,183.5 445.5,193.5"/>
	<text x="369.5" y="209.5" font-family="Times New Roman" font-size="20">a, &#949; &gt; A</text>
	<polygon stroke="black" stroke-width="1" points="513.5,188.5 610.5,188.5"/>
	<polygon fill="black" stroke-width="1" points="610.5,188.5 602.5,183.5 602.5,193.5"/>
	<text x="524.5" y="209.5" font-family="Times New Roman" font-size="20">c, &#949; &gt; BB</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 470.275,161.703 A 22.5,22.5 0 1 1 496.725,161.703"/>
	<text x="452.5" y="112.5" font-family="Times New Roman" font-size="20">a, &#949; &gt; A</text>
	<polygon fill="black" stroke-width="1" points="496.725,161.703 505.473,158.17 497.382,152.292"/>
	<path stroke="black" stroke-width="1" fill="none" d="M 627.275,161.703 A 22.5,22.5 0 1 1 653.725,161.703"/>
	<text x="602.5" y="112.5" font-family="Times New Roman" font-size="20">c, &#949; &gt; BB</text>
	<polygon fill="black" stroke-width="1" points="653.725,161.703 662.473,158.17 654.382,152.292"/>
	<polygon stroke="black" stroke-width="1" points="640.5,218.5 640.5,314.5"/>
	<polygon fill="black" stroke-width="1" points="640.5,314.5 645.5,306.5 635.5,306.5"/>
	<text x="645.5" y="272.5" font-family="Times New Roman" font-size="20">d, B &gt; &#949;</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 509.167,329.101 A 128.512,128.512 0 0 1 614.833,329.101"/>
	<polygon fill="black" stroke-width="1" points="509.167,329.101 518.515,330.37 514.404,321.254"/>
	<text x="530.5" y="308.5" font-family="Times New Roman" font-size="20">d, B &gt; &#949;</text>
	<polygon stroke="black" stroke-width="1" points="453.5,344.5 348.5,344.5"/>
	<polygon fill="black" stroke-width="1" points="348.5,344.5 356.5,349.5 356.5,339.5"/>
	<text x="371.5" y="335.5" font-family="Times New Roman" font-size="20">b, &#949; &gt; &#949;</text>
	<polygon stroke="black" stroke-width="1" points="288.5,344.5 187.5,344.5"/>
	<polygon fill="black" stroke-width="1" points="187.5,344.5 195.5,349.5 195.5,339.5"/>
	<text x="208.5" y="335.5" font-family="Times New Roman" font-size="20">&#949;, $ &gt; &#949;</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 331.725,371.297 A 22.5,22.5 0 1 1 305.275,371.297"/>
	<text x="286.5" y="433.5" font-family="Times New Roman" font-size="20">b, A &gt; &#949;</text>
	<polygon fill="black" stroke-width="1" points="305.275,371.297 296.527,374.83 304.618,380.708"/>
	<path stroke="black" stroke-width="1" fill="none" d="M 619.569,365.823 A 96.5,96.5 0 0 1 504.431,365.823"/>
	<polygon fill="black" stroke-width="1" points="619.569,365.823 610.165,366.582 616.131,374.608"/>
	<text x="530.5" y="405.5" font-family="Times New Roman" font-size="20">d, B &gt; &#949;</text>
</svg>