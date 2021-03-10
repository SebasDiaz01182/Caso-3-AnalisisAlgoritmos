/*
Case#3
Topic: #pointers
Date: 09/03/2021, 9:00 pm 
Team size: two 
Students: 
-Sebastián Díaz Obando
-Sebatián Obando Paniagua
*/
package main

import (
	"fmt"
	"time"
)

func main() {

	start := time.Now()

	time.Sleep(time.Second * 2)

	list := []int{808, 250, 74, 659, 931, 273, 545, 879, 924, 710, 441, 166, 493, 43, 988, 504, 328, 730, 841, 613,
		304, 170, 710, 158, 561, 934, 100, 279, 817, 336, 98, 827, 513, 268, 811, 634, 980, 150, 580, 822, 968, 673,
		394, 337, 486, 746, 229, 92, 195, 358, 2, 154, 709, 945, 669, 491, 125, 197, 531, 904, 723, 667, 550, 25, 802,
		854, 978, 409, 229, 934, 299, 982, 636, 14, 866, 815, 64, 537, 426, 670, 116, 95, 630, 502, 518, 196, 106, 405,
		452, 299, 189, 124, 506, 883, 753, 567, 717, 338, 439, 145, 502, 898, 872, 829, 138, 359, 178, 398, 295, 905, 610,
		232, 746, 176, 636, 299, 143, 400, 969, 413, 261, 558, 595, 9, 396, 969, 114, 531, 7, 963, 943, 366, 83, 853, 768,
		822, 696, 713, 672, 902, 591, 832, 739, 58, 617, 791, 641, 680, 336, 7, 973, 99, 96, 320, 455, 224, 290, 761, 906,
		127, 124, 507, 814, 771, 239, 95, 221, 845, 367, 535, 227, 395, 364, 739, 845, 591, 551, 160, 624, 948, 386, 218,
		273, 540, 248, 386, 497, 886, 624, 421, 145, 969, 736, 916, 626, 535, 43, 12, 680, 153, 245, 296, 819, 397, 693,
		816, 992, 34, 670, 398, 554, 548, 826, 211, 663, 212, 809, 378, 762, 626, 336, 869, 996, 777, 768, 440, 875, 332,
		557, 302, 873, 561, 95, 985, 756, 790, 408, 16, 194, 770, 681, 456, 856, 507, 964, 503, 677, 109, 250, 332, 845,
		639, 809, 998, 652, 850, 204, 732, 532, 15, 420, 776, 10, 181, 930, 224, 55, 261, 738, 546, 318, 526, 201, 257,
		565, 598, 649, 705, 551, 151, 977, 413, 555, 798, 505, 382, 749, 66, 379, 700, 210, 130, 554, 484, 448, 608, 774,
		323, 306, 177, 54, 225, 631, 367, 401, 445, 371, 286, 17, 899, 156, 134, 558, 577, 179, 267, 358, 712, 879, 615,
		820, 738, 134, 592, 721, 763, 634, 198, 32, 589, 590, 874, 878, 305, 359, 201, 255, 961, 916, 948, 481, 731, 956,
		547, 108, 239, 1, 927, 36, 858, 114, 115, 594, 361, 355, 419, 358, 586, 730, 16, 564, 103, 918, 644, 420, 968, 748,
		270, 396, 304, 474, 104, 749, 386, 659, 460, 407, 931, 825, 133, 974, 604, 898, 921, 951, 232, 481, 204, 901, 521,
		534, 259, 4, 677, 951, 935, 781, 880, 833, 575, 550, 543, 250, 772, 311, 880, 984, 971, 41, 724, 651, 972, 230, 319,
		747, 300, 231, 622, 777, 125, 245, 959, 697, 772, 65, 561, 599, 752, 941, 504, 552, 802, 206, 81, 419, 275, 650, 414,
		321, 26, 13, 784, 789, 118, 9, 551, 325, 196, 258, 512, 691, 667, 411, 594, 554, 566, 961, 743, 404, 353, 308, 142, 911,
		201, 800, 128, 172, 788, 415, 626, 642, 518, 349, 843, 316, 975, 446, 374, 221, 912, 240, 55, 306, 930, 254, 190, 167,
		357, 305, 861, 899, 593, 721, 117, 581, 868, 353, 940, 699, 902, 812, 617, 892, 672, 729, 672, 662, 46, 121, 241, 159,
		454, 628, 351, 712, 564, 595, 534, 728, 828, 796, 532, 443, 517, 7, 516, 925, 602, 98, 662, 104, 325, 109, 937, 282, 16,
		711, 217, 906, 974, 782, 721, 792, 170, 866, 828, 537, 729, 126, 385, 168, 950, 477, 47, 577, 667, 468, 521, 385, 992, 211,
		259, 212, 745, 519, 719, 935, 826, 768, 690, 819, 15, 826, 919, 29, 30, 35, 728, 241, 755, 541, 397, 936, 84, 49, 866,
		12, 253, 65, 877, 238, 676, 246, 711, 416, 193, 711, 748, 38, 300, 448, 716, 694, 580, 130, 165, 980, 502, 526, 290,
		959, 34, 801, 90, 671, 218, 847, 39, 544, 339, 937, 322, 720, 497, 248, 789, 360, 988, 36, 236, 913, 685, 990, 785,
		735, 668, 520, 616, 46, 977, 662, 826, 820, 632, 904, 699, 799, 640, 5, 504, 680, 766, 392, 108, 925, 366, 122, 455,
		107, 451, 704, 833, 33, 142, 655, 978, 218, 901, 290, 466, 748, 623, 880, 318, 517, 49, 763, 30, 40, 709, 904, 658,
		762, 753, 467, 622, 558, 997, 956, 931, 495, 556, 222, 313, 294, 428, 233, 445, 792, 199, 153, 857, 571, 304, 440,
		915, 800, 767, 836, 922, 44, 753, 87, 720, 151, 411, 624, 670, 606, 944, 312, 432, 993, 817, 700, 972, 640, 371, 837,
		892, 858, 834, 329, 178, 411, 684, 177, 490, 92, 435, 712, 905, 27, 892, 791, 523, 365, 891, 885, 814, 442, 128, 180,
		785, 538, 871, 562, 582, 166, 803, 733, 333, 855, 760, 848, 378, 463, 11, 820, 151, 378, 942, 837, 721, 300, 113, 760,
		957, 391, 153, 49, 15, 45, 919, 151, 102, 296, 822, 732, 502, 246, 962, 58, 511, 929, 806, 174, 138, 670, 97, 504, 422,
		676, 519, 301, 490, 263, 55, 264, 644, 890, 251, 736, 416, 365, 495, 964, 759, 653, 93, 317, 715, 421, 61, 451, 369, 742,
		848, 197, 788, 502, 235, 129, 572, 449, 876, 254, 872, 330, 294, 720, 472, 821, 765, 80, 631, 411, 81, 114, 343, 139,
		383, 45, 829, 394, 576, 981, 1, 597, 948, 371, 88, 544, 734, 853, 262, 825, 401, 381, 779, 858, 424, 499, 15, 846, 663,
		510, 611, 850, 219, 291, 56, 744, 556, 386, 535, 276, 322, 152, 227, 252, 460, 784, 715, 438, 880, 699, 101, 138, 286,
		879, 285, 343, 916, 961, 68, 141, 708, 567, 729, 563, 364, 970, 891, 624, 279, 314, 762, 11, 841, 979, 1, 395, 508, 657,
		552, 787, 432, 545, 740, 777, 585, 253, 109, 515, 455, 20, 29, 672, 371, 664, 948, 25, 544, 855, 9, 982, 553, 289, 164,
		360, 20, 380, 357, 462, 488, 354, 900, 789, 245, 881, 467, 284, 275, 237, 910, 568, 835, 940, 685, 652, 550, 267, 468,
		111, 590, 328, 774, 582, 296, 937, 875, 436, 232, 973, 29, 799, 71, 588, 298, 90, 647, 91, 112, 613, 464, 113, 782, 952,
		231}
	//fmt.Println("Array Original:", list)
	cocktailSort(list)
	//fmt.Println("Array Ordenado: ", list)

	elapsed := time.Since(start)
	fmt.Printf("Este programa en Go, tomó: %s", elapsed)
}

func cocktailSort(list []int) {
	last := len(list) - 1
	for {
		swapped := false
		for i := 0; i < last; i++ {
			if list[i] > list[i+1] {
				list[i], list[i+1] = list[i+1], list[i]
				swapped = true
			}
		}
		if !swapped {
			return
		}
		swapped = false
		for i := last - 1; i >= 0; i-- {
			if list[i] > list[i+1] {
				list[i], list[i+1] = list[i+1], list[i]
				swapped = true
			}
		}
		if !swapped {
			return
		}
	}
}
