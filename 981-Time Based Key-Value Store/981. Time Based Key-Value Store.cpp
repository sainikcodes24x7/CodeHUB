class TimeMap {
    
    Map<String, TreeMap<Integer, String>> store;

    public TimeMap() {
        store = new HashMap<>();
    }
    
    public void set(String key, String value, int timestamp) {
        store.computeIfAbsent(key, x -> new TreeMap<>()).put(timestamp, value);
    }
    
    public String get(String key, int timestamp) {
        Integer tmp = (store.containsKey(key)) ? store.get(key).floorKey(timestamp) : null;
        return (tmp != null) ? store.get(key).get(tmp) : "";
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */