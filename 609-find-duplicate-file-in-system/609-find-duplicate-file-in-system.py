class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        li=defaultdict(list)
        
        for routes in paths:
            arr=routes.split(" ")
            dir_name=arr[0]
            for file_content in arr[1:]:
                file,content = file_content.split("(")
                li[content[:-1]].append(dir_name+'/'+file)
                
        return  [value for value in li.values() if len(value)>1]        
            