class Solution:
    
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        
        def get_row_mask(row: List[int]) -> int:        
            
            mask = 0
            for shift, value in enumerate(reversed(row)):
                if value:
                    mask |= 1 << shift
            
            return mask
        
        img1_row_masks = [get_row_mask(row) for row in img1]
        img2_row_masks = [get_row_mask(row) for row in img2]
        n = len(img1)
        largest_overlap = 0
        
        for shift in range(n): 
            for start_row in range(n):
                
                total_overlap_1 = 0
                total_overlap_2 = 0
                total_overlap_3 = 0
                total_overlap_4 = 0
                
                for idx in range(start_row, n): 
                    
                    total_overlap_1 += (
                        img1_row_masks[idx - start_row] >> shift & img2_row_masks[idx]
                    ).bit_count()
                    
                    total_overlap_2 += (
                        img1_row_masks[idx] >> shift & img2_row_masks[idx - start_row]
                    ).bit_count()
                    
                    total_overlap_3 += (
                        img1_row_masks[idx - start_row] & img2_row_masks[idx] >> shift
                    ).bit_count()
                    
                    total_overlap_4 += (
                        img1_row_masks[idx] & img2_row_masks[idx - start_row] >> shift
                    ).bit_count()
                    
                    
                largest_overlap = max(
                    largest_overlap, 
                    total_overlap_1,
                    total_overlap_2,
                    total_overlap_3,
                    total_overlap_4,
                )                    

        return largest_overlap