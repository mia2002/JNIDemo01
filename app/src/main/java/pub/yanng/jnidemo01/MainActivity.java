package pub.yanng.jnidemo01;

import android.app.Activity;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity implements View.OnClickListener{

    private Button btnGet,btnSet;
    private EditText etValue;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initView();
    }

    private void initView(){
        btnGet = (Button) findViewById(R.id.btn_get);
        btnSet = (Button) findViewById(R.id.btn_set);
        etValue = (EditText) findViewById(R.id.et_value);
        btnSet.setOnClickListener(this);
        btnGet.setOnClickListener(this);
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()){
            case R.id.btn_get:
                String str = getValueFromC();
                Toast.makeText(MainActivity.this, str,Toast.LENGTH_SHORT).show();
                break;
            case R.id.btn_set:
                String value = etValue.getText().toString();
                if (TextUtils.isEmpty(value)){
                    Toast.makeText(MainActivity.this,"请输入要设置的值",Toast.LENGTH_SHORT).show();
                    etValue.requestFocus();
                    break;
                }
                setValueToC(value);
                break;
            }

        }

    public native String getValueFromC();

    public native void setValueToC(String value);

    static {
        System.loadLibrary("hello");
    }
}
