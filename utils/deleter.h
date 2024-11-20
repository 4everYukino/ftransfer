#include <functional>

class Deleter {
public:
    explicit Deleter(std::function<void()> func) : func_(func), active(true) {

    }

    // 禁止拷贝操作
    Deleter(const Deleter&) = delete;
    Deleter& operator=(const Deleter&) = delete;

    // 允许移动操作
    Deleter(Deleter&& other) noexcept
        : func_(std::move(other.func_)), active(other.active) {
        other.active = false;
    }

    // 析构函数，自动调用清理逻辑
    ~Deleter() {
        if (active && func_) {
            func_();
        }
    }

    // 提供一个手动禁止的接口
    void dismiss() {
        active = false;
    }

private:
    std::function<void()> func_;
    bool active;
};
